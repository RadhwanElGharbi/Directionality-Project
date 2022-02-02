// -----------------------------------------------------------------------------
//  root_macro.c
//
//  Example of a macro for reading the ROOT files produced from the
//  Q_PIX_GEANT4 program.
//   * Author: Everybody is an author!
//   * Creation date: 12 August 2020
// -----------------------------------------------------------------------------

// C++ includes
#include <iostream>
#include <string>
#include <vector>
//#include "matplotlibcpp.h"

// ROOT includes
#include "TBranch.h"
#include "TChain.h"
#include "TFile.h"
#include "TROOT.h"

//------------------------------------------------------------
// forward declarations
//------------------------------------------------------------

// progress bar
void update_progress(double progress, size_t precision);
double last_progress_percentage_ = -1.0;

// set branch addresses
void set_branch_addresses();

// TH3 Histogram
void create_th3_hist(int entryID);

// Cone
std::vector<double> get_vector_2points(double p1_x, double p1_y, double p1_z, double p2_x, double p2_y, double p2_z);
std::vector<double> cross_product(std::vector<double> vector1, std::vector<double> vector2);
double vector_magnitude(std::vector<double> vec);
double distance_point_line_3d(int index);
double get_cone_radius(int index);
bool is_hit_inside_cone(int index, double angle);


// total hit energy deposit
double get_hit_totedep(int entryID);

//------------------------------------------------------------
// input files
//------------------------------------------------------------

std::vector< std::string > file_list_ = {
    "single_electron.root"
};

TChain * chain_ = new TChain("event_tree");

//------------------------------------------------------------
// set up branch variables
//------------------------------------------------------------

int run_;
int event_;
int number_particles_;
int number_hits_;
double energy_deposit_;

std::vector< int >    * particle_track_id_ = 0;
std::vector< int >    * particle_parent_track_id_ = 0;
std::vector< int >    * particle_pdg_code_ = 0;
std::vector< double > * particle_mass_ = 0;
std::vector< double > * particle_charge_ = 0;
std::vector< int >    * particle_process_key_ = 0;
std::vector< int >    * particle_total_occupancy_ = 0;

std::vector< double > * particle_initial_x_ = 0;
std::vector< double > * particle_initial_y_ = 0;
std::vector< double > * particle_initial_z_ = 0;
std::vector< double > * particle_initial_t_ = 0;

std::vector< double > * particle_initial_px_ = 0;
std::vector< double > * particle_initial_py_ = 0;
std::vector< double > * particle_initial_pz_ = 0;
std::vector< double > * particle_initial_energy_ = 0;

std::vector< double > * particle_number_daughters_ = 0;

std::vector< int >    * hit_track_id_ = 0;
std::vector< double > * hit_start_x_ = 0;
std::vector< double > * hit_start_y_ = 0;
std::vector< double > * hit_start_z_ = 0;
std::vector< double > * hit_start_t_ = 0;
std::vector< double > * hit_end_x_ = 0;
std::vector< double > * hit_end_y_ = 0;
std::vector< double > * hit_end_z_ = 0;
std::vector< double > * hit_end_t_ = 0;
std::vector< double > * hit_length_ = 0;
std::vector< double > * hit_energy_deposit_ = 0;
std::vector< int >    * hit_process_key_ = 0;

std::vector< TVector3 > particle_initial_tvector3_;
std::vector< TVector3 > particle_initial_ptvector3_;

double degrees = 180 / (atan(1) * 4);

// set branch addresses
void set_branch_addresses(TChain * chain)
{
  chain->SetBranchAddress("run", &run_);
  chain->SetBranchAddress("event", &event_);
  chain->SetBranchAddress("number_particles", &number_particles_);
  chain->SetBranchAddress("number_hits", &number_hits_);
  chain->SetBranchAddress("energy_deposit", &energy_deposit_);

  chain->SetBranchAddress("particle_track_id", &particle_track_id_);
  chain->SetBranchAddress("particle_parent_track_id", &particle_parent_track_id_);
  chain->SetBranchAddress("particle_pdg_code", &particle_pdg_code_);
  chain->SetBranchAddress("particle_mass", &particle_mass_);
  chain->SetBranchAddress("particle_charge", &particle_charge_);
  chain->SetBranchAddress("particle_process_key", &particle_process_key_);
  chain->SetBranchAddress("particle_total_occupancy", &particle_total_occupancy_);

  chain->SetBranchAddress("particle_initial_x", &particle_initial_x_);
  chain->SetBranchAddress("particle_initial_y", &particle_initial_y_);
  chain->SetBranchAddress("particle_initial_z", &particle_initial_z_);
  chain->SetBranchAddress("particle_initial_t", &particle_initial_t_);

  chain->SetBranchAddress("particle_initial_px", &particle_initial_px_);
  chain->SetBranchAddress("particle_initial_py", &particle_initial_py_);
  chain->SetBranchAddress("particle_initial_pz", &particle_initial_pz_);
  chain->SetBranchAddress("particle_initial_energy", &particle_initial_energy_);
  
  chain->SetBranchAddress("particle_number_daughters", &particle_number_daughters_);

  chain->SetBranchAddress("hit_track_id", &hit_track_id_);

  chain->SetBranchAddress("hit_start_x", &hit_start_x_);
  chain->SetBranchAddress("hit_start_y", &hit_start_y_);
  chain->SetBranchAddress("hit_start_z", &hit_start_z_);
  chain->SetBranchAddress("hit_start_t", &hit_start_t_);

  chain->SetBranchAddress("hit_end_x", &hit_end_x_);
  chain->SetBranchAddress("hit_end_y", &hit_end_y_);
  chain->SetBranchAddress("hit_end_z", &hit_end_z_);
  chain->SetBranchAddress("hit_end_t", &hit_end_t_);

  chain->SetBranchAddress("hit_energy_deposit", &hit_energy_deposit_);
  chain->SetBranchAddress("hit_length", &hit_length_);
  chain->SetBranchAddress("hit_process_key", &hit_process_key_);
} // set_branch_addresses()

//----------------------------------------------------------------------
// main function
//----------------------------------------------------------------------
int main()
{
  //----------------------------------------------------------
  // add files to chain
  //----------------------------------------------------------
  for (auto const& file_name : file_list_)
  {
    chain_->Add(file_name.c_str());
  }

  //----------------------------------------------------------
  // set branch addresses
  //----------------------------------------------------------
  set_branch_addresses(chain_);

  // get number of entries
  size_t const number_entries = chain_->GetEntries();

  std::cout << "There are a total of "
            << number_entries
            << " events in the sample.\n"
            << "Looping over events..."
            << std::endl;

  // loop over events
  for (size_t idx = 0; idx < number_entries; ++idx)
  {
    update_progress(double((idx+1.0) / number_entries), 1);
    chain_->GetEntry(idx);

    // loop over all particles in the event
    for (int p_idx = 0; p_idx < number_particles_; ++p_idx)
    {
      int const track_id = particle_track_id_->at(p_idx);
      int const parent_track_id = particle_parent_track_id_->at(p_idx);
      int const pdg_code = particle_pdg_code_->at(p_idx);
      double const mass = particle_mass_->at(p_idx);  // MeV
      int const process_key = particle_process_key_->at(p_idx);
      double const initial_x = particle_initial_x_->at(p_idx);  // cm
      double const initial_y = particle_initial_y_->at(p_idx);  // cm
      double const initial_z = particle_initial_z_->at(p_idx);  // cm
      double const initial_t = particle_initial_t_->at(p_idx);  // ns
      double const initial_px = particle_initial_px_->at(p_idx);  // MeV
      double const initial_py = particle_initial_py_->at(p_idx);  // MeV
      double const initial_pz = particle_initial_pz_->at(p_idx);  // MeV
      double const initial_energy = particle_initial_energy_->at(p_idx);  // MeV
      double const number_daughters = particle_number_daughters_->at(p_idx); 
    }

    // loop over all hits in the event
    for (int h_idx = 0; h_idx < number_hits_; ++h_idx)
    {
      // track ID of particle responsible for this hit
      int const track_id = hit_track_id_->at(h_idx);

      // from PreStepPoint
      double const start_x = hit_start_x_->at(h_idx);  // cm
      double const start_y = hit_start_y_->at(h_idx);  // cm
      double const start_z = hit_start_z_->at(h_idx);  // cm
      double const start_t = hit_start_t_->at(h_idx);  // ns

      // from PostStepPoint
      double const end_x = hit_end_x_->at(h_idx);  // cm
      double const end_y = hit_end_y_->at(h_idx);  // cm
      double const end_z = hit_end_z_->at(h_idx);  // cm
      double const end_t = hit_end_t_->at(h_idx);  // ns

      // energy deposit
      double const energy_deposit = hit_energy_deposit_->at(h_idx);  // MeV

      // PreStepPoint -> PostStepPoint
      double const length = hit_length_->at(h_idx);  // cm

      // process key
      double const process_key = hit_process_key_->at(h_idx);
    }
  }
  // TESTING CONE
  // TESTING CONE
} // main()

//----------------------------------------------------------------------
// progress bar
//----------------------------------------------------------------------
void update_progress(double progress, size_t precision=1)
{
  size_t const bar_length = 50;
  std::string status = "";

  if (progress < 0)
  {
    progress = 0;
    status = "Halt...";
  }

  if (progress >= 1)
  {
    progress = 1;
    status = "Done!";
  }

  //double const progress_percentage = std::round(progress * 1e6) / 1e4;
  double const progress_percentage =
      std::round(progress * std::pow(10, 2+precision)) / std::pow(10, precision);

  //if (std::fmod(progress_percentage, precision) == 0)
  if (std::fmod(progress_percentage, 1) == 0
      and last_progress_percentage_ != progress_percentage)
  {

    std::cout << "[";
    int pos = bar_length * progress;
    for (size_t i = 0; i < bar_length; ++i)
    {
      if (i < pos) std::cout << "=";
      else if (i == pos) std::cout << ">";
      else std::cout << " ";
    }

    //std::cout << "] " << int(progress_percentage) << "%\r ";
    std::cout << "] " << int(progress_percentage) << "% " << status << "\r";
    std::cout.flush();

    last_progress_percentage_ = progress_percentage;

  }

  if (progress >= 1) std::cout << std::endl;
} // update_progress()

//----------------------------------------------------------------------
// run, forrest, run!
//----------------------------------------------------------------------


void create_th3_hist(int entryID)
{
	chain_->GetEntry(entryID);
	TCanvas* canv = new TCanvas();
	TH3D* hist = new TH3D("e- Xe Hist", "e- tracks and hits in Xe", 100, -120, 120, 100, -120, 120, 100, 0, 2000);
	
	// Initial Particle 
	for(int iter = 0; iter < (*particle_initial_x_).size(); iter++)
	{
	    hist->Fill((*particle_initial_x_)[iter], (*particle_initial_y_)[iter], (*particle_initial_z_)[iter]);
	}
	
	TVector3 particle__momentum((*particle_initial_px_)[0], (*particle_initial_py_)[0], (*particle_initial_pz_)[0]);
	
	for(int iter = 0; iter < (*hit_start_z_).size(); iter++)
	{
		hist->Fill((*hit_start_x_)[iter], (*hit_start_y_)[iter], (*hit_start_z_)[iter]);
		hist->Fill((*hit_end_x_)[iter], (*hit_end_y_)[iter], (*hit_end_z_)[iter]);
	}
	hist->Draw();
}

//=================================CONE START=======================================//

std::vector<double> get_vector_2points(double p1_x, double p1_y, double p1_z, double p2_x, double p2_y, double p2_z)
{
    std::vector<double> newVec;
    newVec.push_back((p1_x - p2_x));
    newVec.push_back((p1_y - p2_y));
    newVec.push_back((p1_z - p2_z));
    return newVec;
}

std::vector<double> cross_product(std::vector<double> vector1, std::vector<double> vector2)
{
    std::vector<double> newVec;
    newVec.push_back((vector1[1]*vector2[2])-(vector1[2]*vector2[1]));
    newVec.push_back((vector1[2] * vector2[0]) - (vector1[0] * vector2[2]));
    newVec.push_back((vector1[0] * vector2[1]) - (vector1[1] * vector2[0]));
    return newVec;
}

double vector_magnitude(std::vector<double> vec)
{
    return sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2));
}

/*double distance_point_line_3d(int index)
{
    // Q (particle_initial_xyz) is point on the line and P (hit_start_xyz) is point off the line
    std::vector<double> vec_qp = get_vector_2points((*particle_initial_x_)[index], (*particle_initial_y_)[index], (*particle_initial_z_)[index], (*hit_start_x_)[index], (*hit_start_y_)[index], (*hit_start_z_)[index]);
    std::vector<double> cone_primary_axis;
    cone_primary_axis.push_back((*particle_initial_px_)[index]);
    cone_primary_axis.push_back((*particle_initial_py_)[index]);
    cone_primary_axis.push_back((*particle_initial_pz_)[index]);
    double numerator = vector_magnitude(cross_product(vec_qp, cone_primary_axis));
    double denominator = vector_magnitude(cone_primary_axis);
    return numerator / denominator;
}*/

double distance_point_line_3d(int index)
{
    // Q (particle_initial_xyz) is point on the line and P (hit_start_xyz_) is point off the line
    std::vector<double> vec_qp = get_vector_2points((*particle_initial_x_)[0], (*particle_initial_y_)[0], (*particle_initial_z_)[0], (*hit_start_x_)[index], (*hit_start_y_)[index], (*hit_start_z_)[index]);
    std::vector<double> cone_primary_axis;
    cone_primary_axis.push_back((*particle_initial_px_)[0]);
    cone_primary_axis.push_back((*particle_initial_py_)[0]);
    cone_primary_axis.push_back((*particle_initial_pz_)[0]);
    double numerator = vector_magnitude(cross_product(vec_qp, cone_primary_axis));
    double denominator = vector_magnitude(cone_primary_axis);
    return numerator / denominator;
}

double get_cone_radius(int index, double angle)
{
    int hypotenuse = sqrt(pow(((*hit_start_x_)[index] - (*particle_initial_x_)[0]), 2) + pow(((*hit_start_y_)[index] - (*particle_initial_y_)[0]), 2) + pow(((*hit_start_z_)[index] - (*particle_initial_z_)[0]), 2));
    int opposite = distance_point_line_3d(index);
    int cone_height = hypotenuse * cos(asin(opposite / hypotenuse));
    //std::cout << cone_height * tan(angle) << std::endl;
    return cone_height * tan(angle);
}

bool is_hit_inside_cone(int index, double angle)
{
    if (get_cone_radius(index, angle) < distance_point_line_3d(index))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void create_cone(int entryID, double angle)
{
    chain_->GetEntry(entryID);
    int count = 0;
    double countDub = 0;
    for (int i = 0; i < (*hit_start_x_).size(); i++)
    {
        if (is_hit_inside_cone(i, (angle/180)* 3.14159265359) == true)
        {
            std::cout << "IN" << std::endl;
            count++;
            countDub++;
        }
        else
        {
            std::cout << "OUT" << std::endl;
        }
    }
    if ((*hit_start_x_).size() == 0)
    {
        std::cout << "No hits in entry ID: " << entryID << std::endl;
    }
    else
    {
        std::cout << "Number of hits inside cone of angle " << angle << " degrees: " << count << "/" << (*hit_start_x_).size() << std::endl;
        std::cout << "Percentage: " << (countDub / (*hit_start_x_).size()) * 100 << "%" << std::endl;
    }

}

//=================================CONE END=======================================//


double get_hit_totedep(int entryID)
{
	chain_->GetEntry(entryID);
	double totedep = 0;
	for(int iter = 0; iter < (*hit_energy_deposit_).size(); iter++)
	{
		totedep+=(*hit_energy_deposit_)[iter];
	}
	
	return totedep;
}

void root_macro()
{
  main();
} // root_macro()

