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
/// \file HistoManager.cc
/// \brief Implementation of the HistoManager class
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "HistoManager.hh"
#include "G4UnitsTable.hh"

HistoManager* HistoManager::instance_ = 0;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::HistoManager()
  : fFileName("rdecay02")
{
  Book();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

HistoManager::~HistoManager()
{
  delete G4AnalysisManager::Instance();
}

HistoManager* HistoManager::Instance()
{
  if (instance_ == 0) instance_ = new HistoManager();
    return instance_;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void HistoManager::Book()
{
  // Create or get analysis manager
  // The choice of analysis technology is done via selection of a namespace
  // in HistoManager.hh
  //
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();
  
  analysis->SetFileName(fFileName);
  analysis->SetVerboseLevel(1);
  analysis->SetActivation(true);     //enable inactivation of histos, nTuples
    
  // Default values (to be reset via /analysis/h1/set command)               
  G4int nbins = 100;
  G4double vmin = 0.;
  G4double vmax = 100.;

  // Create all histograms as inactivated 
  // as we have not yet set nbins, vmin, vmax
  //
  ////analysis->SetHistoDirectoryName("histo");  
  ////analysis->SetFirstHistoId(1);
    
  G4int id = analysis->CreateH1("H10","Energy deposit (MeV) in the target",
                       nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);
    
  id = analysis->CreateH1("H11","Energy deposit (MeV) in the detector",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("H12","Total energy (MeV) in target and detector",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("H13",
                "Coincidence spectrum (MeV) between the target and detector",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);  

  id = analysis->CreateH1("H14",
                "Anti-coincidence spectrum (MeV) in the traget",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("H15",
                "Anti-coincidence spectrum (MeV) in the detector",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);  

  id = analysis->CreateH1("H16","Decay emission spectrum (0 - 10 MeV)",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);  
  
  id = analysis->CreateH1("H17","Decay emission spectrum (0 - 1 MeV)",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("H18","Decay emission spectrum (0 - 0.1 MeV)",
                 nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH3("H30", "Electron Directionality in Volume", nbins, vmin, vmax, nbins, vmin, vmax, nbins, vmin, vmax);
  analysis->SetH3Activation(id, false);
  
  // nTuples
  //
  ////analysis->SetNtupleDirectoryName("ntuple");
  ////analysis->SetFirstNtupleId(1);
  //       
  analysis->CreateNtuple("T1", "Emitted Particles");
  analysis->CreateNtupleDColumn("PID");       //column 0
  analysis->CreateNtupleDColumn("Energy");    //column 1
  analysis->CreateNtupleDColumn("Time");      //column 2
  analysis->CreateNtupleDColumn("Weight");    //column 3
  analysis->FinishNtuple();
  
  analysis->CreateNtuple("T2", "RadioIsotopes");
  analysis->CreateNtupleDColumn("PID");       //column 0
  analysis->CreateNtupleDColumn("Time");      //column 1
  analysis->CreateNtupleDColumn("Weight");    //column 2
  analysis->FinishNtuple();
  
  analysis->CreateNtuple("T3", "Energy depositions");
  analysis->CreateNtupleDColumn("Energy");    //column 0
  analysis->CreateNtupleDColumn("Time");      //column 1
  analysis->CreateNtupleDColumn("Weight");    //column 2
  analysis->FinishNtuple();
  
  analysis->CreateNtuple("RDecayProducts", "All Products of RDecay");
  analysis->CreateNtupleDColumn("PID");       //column 0
  analysis->CreateNtupleDColumn("Z");         //column 1
  analysis->CreateNtupleDColumn("A");         //column 2    
  analysis->CreateNtupleDColumn("Energy");    //column 3
  analysis->CreateNtupleDColumn("Time");      //column 4
  analysis->CreateNtupleDColumn("Weight");    //column 5
  analysis->FinishNtuple();
  
  analysis->SetNtupleActivation(false);   

  //-----------------------------------------------------------//f
    // ROOT output file
    std::string const file_path = "xOutOut.root";

    tfile_ = new TFile(file_path.data(), "recreate", "qpix");
    G4cout << run_  << " " << event_ << " " << number_particles_ << " " << number_hits_ << " " << energy_deposit_ << " " << &particle_track_id_ << " " << &particle_parent_track_id_ << " " << &particle_pdg_code_ << " " << &particle_mass_ << " " << &particle_charge_ << " " << &particle_process_key_ << " " << &particle_initial_x_ << " " << &particle_initial_y_ << " " << &particle_initial_z_ << " " << &particle_initial_t_ << " " << &particle_initial_px_ << " " << &particle_initial_py_ << " " << &particle_initial_pz_ << " " << &particle_initial_energy_ << " " << &particle_number_daughters_ << " " << &particle_daughter_track_ids_ << " " << &hit_track_id_ << " " << &hit_start_x_ << " " << &hit_start_y_ << " " << &hit_start_z_ << " " << &hit_start_t_ << " " << &hit_end_x_ << " " << &hit_end_y_ << " " << &hit_end_z_ << " " << &hit_end_t_ << " " << &hit_energy_deposit_ << " " << &hit_length_ << " " << &hit_process_key_ << G4endl;
    // event tree
    event_tree_ = new TTree("event_tree", "event tree");

    event_tree_->Branch("run",   &run_,   "run/I");
    event_tree_->Branch("event", &event_, "event/I");

    event_tree_->Branch("number_particles", &number_particles_, "number_particles/I");
    event_tree_->Branch("number_hits",      &number_hits_,      "number_hits/I");

    event_tree_->Branch("energy_deposit",   &energy_deposit_,   "energy_deposit/D");

    event_tree_->Branch("particle_track_id",        &particle_track_id_);
    event_tree_->Branch("particle_parent_track_id", &particle_parent_track_id_);
    event_tree_->Branch("particle_pdg_code",        &particle_pdg_code_);
    event_tree_->Branch("particle_mass",            &particle_mass_);
    event_tree_->Branch("particle_charge",          &particle_charge_);
    event_tree_->Branch("particle_process_key",     &particle_process_key_);
    event_tree_->Branch("particle_total_occupancy", &particle_total_occupancy_);
    event_tree_->Branch("particle_initial_x",       &particle_initial_x_);
    event_tree_->Branch("particle_initial_y",       &particle_initial_y_);
    event_tree_->Branch("particle_initial_z",       &particle_initial_z_);
    event_tree_->Branch("particle_initial_t",       &particle_initial_t_);
    event_tree_->Branch("particle_initial_px",      &particle_initial_px_);
    event_tree_->Branch("particle_initial_py",      &particle_initial_py_);
    event_tree_->Branch("particle_initial_pz",      &particle_initial_pz_);
    event_tree_->Branch("particle_initial_energy",  &particle_initial_energy_);

    event_tree_->Branch("particle_number_daughters",  &particle_number_daughters_);
    event_tree_->Branch("particle_daughter_track_id", &particle_daughter_track_ids_);

    event_tree_->Branch("hit_track_id",       &hit_track_id_);
    event_tree_->Branch("hit_start_x",        &hit_start_x_);
    event_tree_->Branch("hit_start_y",        &hit_start_y_);
    event_tree_->Branch("hit_start_z",        &hit_start_z_);
    event_tree_->Branch("hit_start_t",        &hit_start_t_);
    event_tree_->Branch("hit_end_x",          &hit_end_x_);
    event_tree_->Branch("hit_end_y",          &hit_end_y_);
    event_tree_->Branch("hit_end_z",          &hit_end_z_);
    event_tree_->Branch("hit_end_t",          &hit_end_t_);
    event_tree_->Branch("hit_energy_deposit", &hit_energy_deposit_);
    event_tree_->Branch("hit_length",         &hit_length_);
    event_tree_->Branch("hit_process_key",    &hit_process_key_);

  //-----------------------------------------------------------//
}



void HistoManager::Save()
{
    // write TTree objects to file and close file
    G4cout << "LINE 217 HistoManager.cpp" << G4endl;
    tfile_->cd();
    G4cout << "LINE 219 HistoManager.cpp" << G4endl;
    //event_tree_->Write();
    G4cout << "LINE 221 HistoManager.cpp" << G4endl;
    tfile_->Close();
    G4cout << "LINE 223 HistoManager.cpp" << G4endl;
}

void HistoManager::EventFill()
{
    // fill TTree objects per event
    event_tree_->Fill();
}

void HistoManager::EventReset()
{
    // reset event variables after filling TTree objects per event
    event_ = -1;
    number_particles_ = 0;

    number_hits_ = 0;
    energy_deposit_ = 0;

    particle_track_id_.clear();
    particle_parent_track_id_.clear();
    particle_pdg_code_.clear();
    particle_mass_.clear();
    particle_charge_.clear();
    particle_process_key_.clear();
    particle_total_occupancy_.clear();

    particle_number_daughters_.clear();
    particle_daughter_track_ids_.clear();

    particle_initial_x_.clear();
    particle_initial_y_.clear();
    particle_initial_z_.clear();
    particle_initial_t_.clear();

    particle_initial_px_.clear();
    particle_initial_py_.clear();
    particle_initial_pz_.clear();
    particle_initial_energy_.clear();

    hit_track_id_.clear();
    hit_start_x_.clear();
    hit_start_y_.clear();
    hit_start_z_.clear();
    hit_start_t_.clear();
    hit_end_x_.clear();
    hit_end_y_.clear();
    hit_end_z_.clear();
    hit_end_t_.clear();
    hit_energy_deposit_.clear();
    hit_length_.clear();
    hit_process_key_.clear();
}


void HistoManager::SetRun(int const value)
{
    run_ = value;
}

void HistoManager::SetEvent(int const value)
{
    event_ = value;
}

void HistoManager::AddMCParticle(MCParticle const * particle)
{
    particle_track_id_.push_back(particle->TrackID());
    particle_parent_track_id_.push_back(particle->ParentTrackID());
    particle_pdg_code_.push_back(particle->PDGCode());
    particle_mass_.push_back(particle->Mass());
    particle_charge_.push_back(particle->Charge());
    particle_process_key_.push_back(this->ProcessToKey(particle->Process()));
    particle_total_occupancy_.push_back(particle->TotalOccupancy());

    particle_initial_x_.push_back(particle->InitialPosition().X());
    particle_initial_y_.push_back(particle->InitialPosition().Y());
    particle_initial_z_.push_back(particle->InitialPosition().Z());
    particle_initial_t_.push_back(particle->InitialPosition().T());
    G4cout << "PARTICLE INITIAL POSITION: (" << particle->InitialPosition().X() << ", " << particle->InitialPosition().Z() << ", " << particle->InitialPosition().Z() << ")" << G4endl;

    particle_initial_px_.push_back(particle->InitialMomentum().X());
    particle_initial_py_.push_back(particle->InitialMomentum().Y());
    particle_initial_pz_.push_back(particle->InitialMomentum().Z());
    particle_initial_energy_.push_back(particle->InitialMomentum().E());

    particle_number_daughters_.push_back(particle->NumberDaughters());
    particle_daughter_track_ids_.push_back(particle->Daughters());

    number_particles_ += 1;

    std::vector< TrajectoryHit > const hits = particle->Hits();

    for (auto const & hit : hits)
    {
        energy_deposit_ += hit.Energy();

        hit_track_id_.push_back(hit.TrackID());

        hit_start_x_.push_back(hit.StartPoint().X());
        hit_start_y_.push_back(hit.StartPoint().Y());
        hit_start_z_.push_back(hit.StartPoint().Z());
        hit_start_t_.push_back(hit.StartTime());
        G4cout << "HIT START POINT: (" << hit.StartPoint().X() << ", " << hit.StartPoint().Y() << ", " << hit.StartPoint().Z() << ")" << G4endl;


        hit_end_x_.push_back(hit.EndPoint().X());
        hit_end_y_.push_back(hit.EndPoint().Y());
        hit_end_z_.push_back(hit.EndPoint().Z());
        hit_end_t_.push_back(hit.EndTime());
        G4cout << "HIT END POINT: (" << hit.EndPoint().X() << ", " << hit.EndPoint().Y() << ", " << hit.EndPoint().Z() << ")" << G4endl;

        hit_length_.push_back(hit.Length());
        hit_energy_deposit_.push_back(hit.Energy());

        hit_process_key_.push_back(this->ProcessToKey(hit.Process()));
        number_hits_ += 1;
    }
  G4cout << "END OF ADDMCPARTICLE" << G4endl;
}

int HistoManager::ProcessToKey(std::string const & process)
{
    int key = -1;

    if      (process.compare("primary")              == 0) key =  0;
    else if (process.compare("eIoni")                == 0) key =  1;
    else if (process.compare("msc")                  == 0) key =  2;
    else if (process.compare("compt")                == 0) key =  3;
    else if (process.compare("phot")                 == 0) key =  4;
    else if (process.compare("eBrem")                == 0) key =  5;
    else if (process.compare("ionIoni")              == 0) key =  6;
    else if (process.compare("hIoni")                == 0) key =  7;
    else if (process.compare("RadioactiveDecayBase") == 0) key =  8;
    else if (process.compare("CoulombScat")          == 0) key =  9;
    else if (process.compare("Rayl")                 == 0) key = 10;
    else if (process.compare("Transportation")       == 0) key = 11;
    else if (process.compare("annihil")              == 0) key = 12;
    else if (process.compare("conv")                 == 0) key = 13;
    else if (process.compare("hadElastic")           == 0) key = 14;
    else if (process.compare("nCapture")             == 0) key = 15;
    else if (process.compare("neutronInelastic")     == 0) key = 16;
    else if (process.compare("photonNuclear")        == 0) key = 17;

    return key;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
