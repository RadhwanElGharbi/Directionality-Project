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
/// \file HistoManager.hh
/// \brief Definition of the HistoManager class
//
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef HistoManager_h
#define HistoManager_h 1

#include "globals.hh"
#include "MCParticle.hh"

// ROOT includes
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

// C++ includes
#include <map>
#include <set>

#include "g4root.hh"
//#include "g4xml.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class HistoManager
{
  public:
   HistoManager();
  ~HistoManager();

   void Book();
   void Save();
   void EventFill();
   void EventReset();

   void SetRun(int const);
   void SetEvent(int const);

   void AddMCParticle(MCParticle const *);

   int ProcessToKey(std::string const &);

   inline void AddProcess(std::string const & process) { process_names_.insert(process); }
   inline std::set< std::string > GetProcessNames() const { return process_names_; }

   static HistoManager* Instance();

  private:
    G4String fFileName;

	static HistoManager * instance_;

        std::set< std::string > process_names_;

        // ROOT objects
        TFile * tfile_;
        TTree * event_tree_;

        // variables that will go into the event trees
        int run_;
        int event_;

        int number_particles_;
        int number_hits_;

        double energy_deposit_;

        std::vector< int >    particle_track_id_;
        std::vector< int >    particle_parent_track_id_;
        std::vector< int >    particle_pdg_code_;
        std::vector< double > particle_mass_;
        std::vector< double > particle_charge_;
        std::vector< int >    particle_process_key_;
        std::vector< int >    particle_total_occupancy_;

        std::vector< int >                particle_number_daughters_;
        std::vector< std::vector< int > > particle_daughter_track_ids_;

        std::vector< double > particle_initial_x_;
        std::vector< double > particle_initial_y_;
        std::vector< double > particle_initial_z_;
        std::vector< double > particle_initial_t_;

        std::vector< double > particle_initial_px_;
        std::vector< double > particle_initial_py_;
        std::vector< double > particle_initial_pz_;
        std::vector< double > particle_initial_energy_;

        std::vector< int >    hit_track_id_;
        std::vector< double > hit_start_x_;
        std::vector< double > hit_start_y_;
        std::vector< double > hit_start_z_;
        std::vector< double > hit_start_t_;
        std::vector< double > hit_end_x_;
        std::vector< double > hit_end_y_;
        std::vector< double > hit_end_z_;
        std::vector< double > hit_end_t_;
        std::vector< double > hit_length_;
        std::vector< double > hit_energy_deposit_;
        std::vector< int >    hit_process_key_;


};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

