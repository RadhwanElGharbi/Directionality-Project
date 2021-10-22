//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file EventAction.cc
/// \brief Implementation of the EventAction class
//
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "EventAction.hh"

#include "Run.hh"
#include "HistoManager.hh"
#include "MCTruthManager.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction()
:G4UserEventAction(),
 fEdep1(0.), fEdep2(0.), fEdep3(0.), fEdep4(0.), fWeight1(0.), fWeight2(0.), fWeight3(0.), fWeight4(0.),
 fTime0(-1*s)
{ } 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event*)
{
  fEdep1 = fEdep2 = fEdep3 = fEdep4 = fWeight1 = fWeight2 = fWeight3 = fWeight4 = 0.;
  fTime0 = -1*s;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::AddEdep(G4int iVol, G4double edep,
                                      G4double time, G4double weight)
{
  // initialize t0
  if (fTime0 < 0.) fTime0 = time;
  
  // out of time window ?
  const G4double TimeWindow (1*microsecond);
  /*if (std::fabs(time - fTime0) > TimeWindow) return;
  
  if (iVol == 1) { fEdep1 += edep; fWeight1 += edep*weight;}
  if (iVol == 2) { fEdep2 += edep; fWeight2 += edep*weight;} 
  if (iVol == 3) { fEdep3 += edep; fWeight3 += edep*weight;} 
  if (iVol == 4) { fEdep4 += edep; fWeight4 += edep*weight;} */ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
 G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
 
 /*G4double Etot = fEdep1 + fEdep2 + fEdep3 + fEdep4;
 G4double Wtot = (fWeight1 + fWeight2 + fWeight3 + fWeight4)/Etot;
 
 // pulse height in target
 //
 if (fEdep1 > 0.) {
   fWeight1 /= fEdep1;
   analysisManager->FillH1(0, fEdep1, fWeight1);   
 }
 
 // pulse height in detector
 //   
 if (fEdep2 > 0.) {
   fWeight2 /= fEdep2;
   analysisManager->FillH1(1, fEdep2, fWeight2);
 }

 // pulse height in gap
 //   
 if (fEdep3 > 0.) {
   fWeight3 /= fEdep3;
   analysisManager->FillH1(1, fEdep3, fWeight3);
 }
 // pulse height in shield
 //   
 if (fEdep4 > 0.) {
   fWeight4 /= fEdep4;
   analysisManager->FillH1(1, fEdep4, fWeight4);
 }
   
 // total
 //
 analysisManager->FillH1(2, Etot, Wtot);
 
 // threshold in target, detector, gap, and shield        
 const G4double Threshold1(10*keV), Threshold2(10*keV), Threshold3(10*keV), Threshold4(10*keV);
  
 //coincidence, anti-coincidences 
 //  
 G4bool coincidence       = ((fEdep1 >= Threshold1) && (fEdep2 >= Threshold2));
 G4bool anti_coincidence1 = ((fEdep1 >= Threshold1) && (fEdep2 <  Threshold2));
 G4bool anti_coincidence2 = ((fEdep1 <  Threshold1) && (fEdep2 >= Threshold2)); 

 if (coincidence)       analysisManager->FillH1(3, fEdep2, fWeight2);
 if (anti_coincidence1) analysisManager->FillH1(4, fEdep1, fWeight1);
 if (anti_coincidence2) analysisManager->FillH1(5, fEdep2, fWeight2); 

 // pass energies to Run
 //  
 Run* run = static_cast<Run*>(
            G4RunManager::GetRunManager()->GetNonConstCurrentRun());
             
 run->AddEdep (fEdep1, fEdep2, fEdep3, fEdep4);  */   

 //----------------------------------------------------------------------------------------------------------------------------------------//
// get MC truth manager
    MCTruthManager * mc_truth_manager = MCTruthManager::Instance();

    // get map of particles from MC truth manager
    auto const MCParticleMap = mc_truth_manager->GetMCParticleMap();

    double energy_deposited = 0.;

    // add particle to analysis manager
    for (auto const& p : MCParticleMap)
    {
        auto const& particle = p.second;
        energy_deposited += particle->EnergyDeposited();
        // std::cout << "Energy deposited by particle PDG (" << particle->PDGCode() << "): " << particle->EnergyDeposited() << std::endl;
    }

    int mod = event->GetEventID() % 1000;
    if (mod == 0)
    {
        G4cout << "Event " << event->GetEventID() << "..." << G4endl;
        // G4cout << "Energy threshold: " << energy_threshold_ << G4endl;
        // G4cout << "Total energy deposited: " << energy_deposited << G4endl;
    }

    // don't save event if total energy deposited is below the energy threshold
    if (energy_deposited < energy_threshold_)
    {
        // get analysis manager
        HistoManager * histo_manager = HistoManager::Instance();

        // reset event variables
        histo_manager->EventReset();

        // reset event in MC truth manager
        mc_truth_manager->EventReset();

        return;
    }

    // get analysis manager
    HistoManager * histo_manager = HistoManager::Instance();

    // set event number
    // event->SetEventID(event->GetEventID() + event_id_offset_);
    // analysis_manager->SetEvent(event->GetEventID());
    histo_manager->SetEvent(event->GetEventID() + event_id_offset_);

    // get map of particles from MC truth manager
    // auto const MCParticleMap = mc_truth_manager->GetMCParticleMap();

    // add particle to analysis manager
    for (auto const& p : MCParticleMap)
    {
        auto const& particle = p.second;

        histo_manager->AddMCParticle(particle);
    }
    G4cout << "LINE 202 EventAction.cpp" << G4endl;
    // write event to ROOT file and reset event variables
    histo_manager->EventFill();
    G4cout << "LINE 205 EventAction.cpp" << G4endl;
    histo_manager->EventReset();
    G4cout << "LINE 207 EventAction.cpp" << G4endl;

    // reset event in MC truth manager
    mc_truth_manager->EventReset();
    G4cout << "LINE 211 EventAction.cpp" << G4endl;
 //----------------------------------------------------------------------------------------------------------------------------------------//

        
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


