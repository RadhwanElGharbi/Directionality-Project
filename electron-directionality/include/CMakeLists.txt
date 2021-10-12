## ---------------------------------------------------------
##  G4_directionality01| include/CMakeLists.txt
##
##  CMake build script.
##   * Author: Justo Martin-Albo
##   * Creation date: 14 Aug 2019
## ---------------------------------------------------------

include_directories(${CMAKE_SOURCE_DIR}/include)

SET(SRC   ActionInitialization.cc
          BiasedRDPhysics.cc
          DetectorConstruction.cc
          DetectorMessenger.cc
          EventAction.cc
          HistoManager.cc
          HitsAction.cc
          MCParticle.cc
          MCTruthManager.cc
          PhysicsList.cc
          PrimaryGeneratorAction.cc
          Run.cc
          RunAction.cc
          SteppingAction.cc
          SteppingVerbose.cc
          TrackingAction.cc
)

# generate ROOT dictionary
ROOT_GENERATE_DICTIONARY(DirectionG4Dict HistoManager.hh LINKDEF LinkDef.h)

add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC} DirectionG4Dict.cxx)
target_link_libraries(${PROJECT_NAME} stdc++fs)

