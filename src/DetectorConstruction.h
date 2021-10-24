// -----------------------------------------------------------------------------
//  G4_QPIX | DetectorConstruction.h
//
//  Class for the definition of the detector geometry and materials.
//   * Author: Justo Martin-Albo
//   * Creation date: 14 Aug 2019
// -----------------------------------------------------------------------------

#ifndef DETECTOR_CONSTRUCTION_H
#define DETECTOR_CONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"
#include "DetectorMessenger.hh"

class G4Material;


class DetectorConstruction: public G4VUserDetectorConstruction
{
public:

  DetectorConstruction();
  virtual ~DetectorConstruction();

public:
    
  G4double GetTargetLength();
  G4double GetTargetRadius();
  G4Material* GetTargetMaterial();       
  G4LogicalVolume* GetLogicTarget();
  
  void PrintParameters();

public:

  void SetTargetLength (G4double value);
  void SetTargetRadius (G4double value);
  void SetTargetMaterial (G4String);

private:

  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();
          void DefineMaterials();

private:

  G4double           fTargetLength;
  G4double           fTargetRadius;
  G4Material*        fTargetMater;
  G4LogicalVolume*   fLogicTarget;

  G4double           fWorldLength;
  G4double           fWorldRadius;
  G4Material*        fWorldMater;
  G4VPhysicalVolume* fPhysiWorld;

  G4Material* mXenon;
  G4Material* mXenon136;
    
  G4double targetPressure;
  G4double gapPressure;
  const G4double molarMassXe = 131.292;
  const G4double molarMassXe136 = 135.91;
  G4double densityXe;
  G4double densityXe136;
                
  DetectorMessenger* fDetectorMessenger;

};

#endif
