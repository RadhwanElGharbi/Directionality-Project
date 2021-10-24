// -----------------------------------------------------------------------------
//  G4_QPIX | DetectorConstruction.cpp
//
//  Definition of detector geometry and materials.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#include "DetectorConstruction.h"
#include "TrackingSD.h"
#include "DetectorMessenger.hh"

#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4SDManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"


DetectorConstruction::DetectorConstruction(): G4VUserDetectorConstruction(), fTargetMater(0), fLogicTarget(0)
{
  fTargetLength      = 24*m;
  fTargetRadius      = 12*m;
  fWorldLength = fTargetLength + (5.0*cm);
  fWorldRadius = fTargetRadius + (1.0*cm);

  DefineMaterials();

  fDetectorMessenger = new DetectorMessenger(this);
}

void DetectorConstruction::DefineMaterials()
{
  // target density
  targetPressure=15;
  densityXe = ((targetPressure*molarMassXe)/(0.0821*275))/1E3;
  densityXe136 = 80.3; //kg/m3

  // build materials
  //
  mXenon = new G4Material("Xenon", 54, molarMassXe*g/mole, densityXe*g/cm3, kStateGas, 275.*kelvin, targetPressure=15*atmosphere);
  mXenon136 = new G4Material("Xenon136", 54, molarMassXe136*g/mole, densityXe136*kg/m3, kStateGas, 275.*kelvin, targetPressure=15*atmosphere);

  G4Element* N  = new G4Element("Nitrogen", "N", 7, 14.01*g/mole);
  G4Element* O  = new G4Element("Oxygen",   "O", 8, 15.9994*g/mole);
  //
  G4int ncomponents; G4double fractionmass;
  G4Material* Air20 = new G4Material("Air", 1.205*mg/cm3, ncomponents=2,
                      kStateGas, 293.*kelvin, 1.*atmosphere);
    Air20->AddElement(N, fractionmass=0.7);
    Air20->AddElement(O, fractionmass=0.3);
  //
  fWorldMater = Air20;

  // fShieldMater Stainless steel
  G4Element* Cr = new G4Element("Chromium", "Cr", 24, 51.996*g/mole);
  G4Element* C = new G4Element("Carbon", "C", 6, 12.011*g/mole);
  G4Element* Mn = new G4Element("Manganese", "Mn", 25, 54.938*g/mole);
  G4Element* Si = new G4Element("Silicon", "Si", 14, 28.085*g/mole);
  G4Element* P = new G4Element("Phosphorous", "P", 15, 30.974*g/mole);
  G4Element* S = new G4Element("Sulphur", "S", 16, 32.06*g/mole);
  G4Element* Ni = new G4Element("Nickel", "Ni", 28, 58.693*g/mole);
  G4Element* Fe = new G4Element("Iron", "Fe", 26, 55.845*g/mole);

  fTargetMater = mXenon;

 ///G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}


DetectorConstruction::~DetectorConstruction()
{delete fDetectorMessenger;}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // WORLD /////////////////////////////////////////////////

  fWorldLength = fTargetLength + (5.0*cm);
  fWorldRadius = fTargetRadius + (1.0*cm);

  G4Tubs*
  sWorld = new G4Tubs("World",                                 //name
                 0.,fWorldRadius, 0.5*fWorldLength, 0.,twopi); //dimensions

  G4LogicalVolume*
  lWorld = new G4LogicalVolume(sWorld,                  //shape
                             fWorldMater,               //material
                             "World");                  //name

  fPhysiWorld = new G4PVPlacement(0,                    //no rotation
                            G4ThreeVector(),            //at (0,0,0)
                            lWorld,                     //logical volume
                            "World",                    //name
                            0,                          //mother volume
                            false,                      //no boolean operation
                            0);                         //copy number

  // Target //////////////////////////////////////////////

  G4Tubs*
  sTarget = new G4Tubs("Target",                                   //name
                  0., fTargetRadius, 0.5*fTargetLength, 0.,twopi); //dimensions


  fLogicTarget = new G4LogicalVolume(sTarget,           //shape
                             fTargetMater,              //material
                             "Target");                 //name

           new G4PVPlacement(0,                         //no rotation
                           G4ThreeVector(),             //at (0,0,0)
                           fLogicTarget,                //logical volume
                           "Target",                    //name
                           lWorld,                      //mother  volume
                           false,                       //no boolean operation
                           0);                          //copy number

  //////////////////////////////////////////////////////////
  PrintParameters();


  return fPhysiWorld;
}

void DetectorConstruction::ConstructSDandField()
{
  // SENSITIVE DETECTOR ////////////////////////////////////

  TrackingSD* tracking_sd = new TrackingSD("/G4QPIX/TRACKING", "TrackingHitsCollection");
  G4SDManager::GetSDMpointer()->AddNewDetector(tracking_sd);

  G4LogicalVolume* detector_logic_vol =
    G4LogicalVolumeStore::GetInstance()->GetVolume("Target");

  SetSensitiveDetector(fLogicTarget, tracking_sd);

  //////////////////////////////////////////////////////////
}

void DetectorConstruction::PrintParameters()
{

  G4cout << "\n Target : Length = " << G4BestUnit(fTargetLength,"Length")
         << " Radius = " << G4BestUnit(fTargetRadius,"Length")
         << " Material = " << fTargetMater->GetName();

  G4cout << "\n" << fTargetMater << G4endl;

}

void DetectorConstruction::SetTargetMaterial(G4String materialChoice)
{
  // search the material by its name
  G4Material* pttoMaterial =
     G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);

  if (pttoMaterial) {
    fTargetMater = pttoMaterial;
    if(fLogicTarget) { fLogicTarget->SetMaterial(fTargetMater); }
    G4RunManager::GetRunManager()->PhysicsHasBeenModified();
  } else {
    G4cout << "\n--> warning from DetectorConstruction::SetTargetMaterial : "
           << materialChoice << " not found" << G4endl;
  }
}

void DetectorConstruction::SetTargetRadius(G4double value)
{
  fTargetRadius = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

void DetectorConstruction::SetTargetLength(G4double value)
{
  fTargetLength = value;
  G4RunManager::GetRunManager()->ReinitializeGeometry();
}

G4double DetectorConstruction::GetTargetLength()
{
  return fTargetLength;
}

G4double DetectorConstruction::GetTargetRadius()
{
  return fTargetRadius;
}

G4Material* DetectorConstruction::GetTargetMaterial()
{
  return fTargetMater;
}

G4LogicalVolume* DetectorConstruction::GetLogicTarget()
{
  return fLogicTarget;
}
