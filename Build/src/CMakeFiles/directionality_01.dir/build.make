# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/local1/Geant4_Project/Directionality-Project/electron_directionality

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build

# Include any dependencies generated for this target.
include src/CMakeFiles/directionality_01.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/directionality_01.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/directionality_01.dir/flags.make

src/QPixG4Dict.cxx: ../src/LinkDef.h
src/QPixG4Dict.cxx: ../src/AnalysisManager.h
src/QPixG4Dict.cxx: ../src/AnalysisManager.h
src/QPixG4Dict.cxx: ../src/LinkDef.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating QPixG4Dict.cxx, libQPixG4Dict_rdict.pcm, libQPixG4Dict.rootmap"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /usr/bin/cmake -E env LD_LIBRARY_PATH=/usr/local/root/6.18.04/lib:/usr/local/root/6.18.04/lib:/usr/local/lib64:/usr/local/geant4/10.07.p02/lib64:/usr/local/clhep/2.4.4.0/lib:/usr/local/XercesC/3.2.3/lib:/usr/lib64:/usr/lib:/usr/local/OpenScientist/16.11.8/lib:/usr/local/OpenScientist/16.11.8/bin:/lib64 /usr/local/root/6.18.04/bin/rootcling -v2 -f QPixG4Dict.cxx -s /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/libQPixG4Dict.so -rml libQPixG4Dict.so -rmf /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/libQPixG4Dict.rootmap -DG4UI_USE_TCSH -DG4INTY_USE_QT -DG4UI_USE_QT -DG4VIS_USE_OPENGLQT -DG4INTY_USE_XT -DG4UI_USE_XM -DG4VIS_USE_OPENGLXM -DG4VIS_USE_OPENGLX -DG4VIS_USE_OPENGL -I/usr/local/clhep/2.4.4.0/lib/CLHEP-2.4.4.0/../../include -I/usr/local/geant4.10.07.p02/include/Geant4 -I/usr/local/root/6.18.04/include -I/home/local1/Geant4_Project/Directionality-Project/electron_directionality/src AnalysisManager.h /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/LinkDef.h

src/libQPixG4Dict_rdict.pcm: src/QPixG4Dict.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate src/libQPixG4Dict_rdict.pcm

src/libQPixG4Dict.rootmap: src/QPixG4Dict.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate src/libQPixG4Dict.rootmap

src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o: ../src/AnalysisManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/AnalysisManager.cpp

src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/AnalysisManager.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/AnalysisManager.cpp > CMakeFiles/directionality_01.dir/AnalysisManager.cpp.i

src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/AnalysisManager.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/AnalysisManager.cpp -o CMakeFiles/directionality_01.dir/AnalysisManager.cpp.s

src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o: ../src/GeneratorParticle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/GeneratorParticle.cpp

src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/GeneratorParticle.cpp > CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.i

src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/GeneratorParticle.cpp -o CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.s

src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o: ../src/MCTruthManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCTruthManager.cpp

src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/MCTruthManager.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCTruthManager.cpp > CMakeFiles/directionality_01.dir/MCTruthManager.cpp.i

src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/MCTruthManager.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCTruthManager.cpp -o CMakeFiles/directionality_01.dir/MCTruthManager.cpp.s

src/CMakeFiles/directionality_01.dir/MCParticle.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/MCParticle.cpp.o: ../src/MCParticle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/directionality_01.dir/MCParticle.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/MCParticle.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCParticle.cpp

src/CMakeFiles/directionality_01.dir/MCParticle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/MCParticle.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCParticle.cpp > CMakeFiles/directionality_01.dir/MCParticle.cpp.i

src/CMakeFiles/directionality_01.dir/MCParticle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/MCParticle.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/MCParticle.cpp -o CMakeFiles/directionality_01.dir/MCParticle.cpp.s

src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o: ../src/DetectorConstruction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorConstruction.cpp

src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorConstruction.cpp > CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.i

src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorConstruction.cpp -o CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.s

src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o: ../src/DetectorMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorMessenger.cc

src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/DetectorMessenger.cc.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorMessenger.cc > CMakeFiles/directionality_01.dir/DetectorMessenger.cc.i

src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/DetectorMessenger.cc.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/DetectorMessenger.cc -o CMakeFiles/directionality_01.dir/DetectorMessenger.cc.s

src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o: ../src/PrimaryGeneration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/PrimaryGeneration.cpp

src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/PrimaryGeneration.cpp > CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.i

src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/PrimaryGeneration.cpp -o CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.s

src/CMakeFiles/directionality_01.dir/RunAction.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/RunAction.cpp.o: ../src/RunAction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/directionality_01.dir/RunAction.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/RunAction.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/RunAction.cpp

src/CMakeFiles/directionality_01.dir/RunAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/RunAction.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/RunAction.cpp > CMakeFiles/directionality_01.dir/RunAction.cpp.i

src/CMakeFiles/directionality_01.dir/RunAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/RunAction.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/RunAction.cpp -o CMakeFiles/directionality_01.dir/RunAction.cpp.s

src/CMakeFiles/directionality_01.dir/EventAction.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/EventAction.cpp.o: ../src/EventAction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/directionality_01.dir/EventAction.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/EventAction.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/EventAction.cpp

src/CMakeFiles/directionality_01.dir/EventAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/EventAction.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/EventAction.cpp > CMakeFiles/directionality_01.dir/EventAction.cpp.i

src/CMakeFiles/directionality_01.dir/EventAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/EventAction.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/EventAction.cpp -o CMakeFiles/directionality_01.dir/EventAction.cpp.s

src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.o: ../src/SteppingAction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/SteppingAction.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SteppingAction.cpp

src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/SteppingAction.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SteppingAction.cpp > CMakeFiles/directionality_01.dir/SteppingAction.cpp.i

src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/SteppingAction.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SteppingAction.cpp -o CMakeFiles/directionality_01.dir/SteppingAction.cpp.s

src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.o: ../src/TrackingAction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/TrackingAction.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingAction.cpp

src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/TrackingAction.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingAction.cpp > CMakeFiles/directionality_01.dir/TrackingAction.cpp.i

src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/TrackingAction.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingAction.cpp -o CMakeFiles/directionality_01.dir/TrackingAction.cpp.s

src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.o: ../src/TrackingSD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/TrackingSD.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingSD.cpp

src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/TrackingSD.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingSD.cpp > CMakeFiles/directionality_01.dir/TrackingSD.cpp.i

src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/TrackingSD.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingSD.cpp -o CMakeFiles/directionality_01.dir/TrackingSD.cpp.s

src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.o: ../src/TrackingHit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/TrackingHit.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingHit.cpp

src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/TrackingHit.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingHit.cpp > CMakeFiles/directionality_01.dir/TrackingHit.cpp.i

src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/TrackingHit.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/TrackingHit.cpp -o CMakeFiles/directionality_01.dir/TrackingHit.cpp.s

src/CMakeFiles/directionality_01.dir/Supernova.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/Supernova.cpp.o: ../src/Supernova.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/directionality_01.dir/Supernova.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/Supernova.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/Supernova.cpp

src/CMakeFiles/directionality_01.dir/Supernova.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/Supernova.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/Supernova.cpp > CMakeFiles/directionality_01.dir/Supernova.cpp.i

src/CMakeFiles/directionality_01.dir/Supernova.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/Supernova.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/Supernova.cpp -o CMakeFiles/directionality_01.dir/Supernova.cpp.s

src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o: ../src/SupernovaTiming.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SupernovaTiming.cpp

src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SupernovaTiming.cpp > CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.i

src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src/SupernovaTiming.cpp -o CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.s

src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o: src/CMakeFiles/directionality_01.dir/flags.make
src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o: src/QPixG4Dict.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o -c /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/QPixG4Dict.cxx

src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.i"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/QPixG4Dict.cxx > CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.i

src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.s"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/QPixG4Dict.cxx -o CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.s

# Object files for target directionality_01
directionality_01_OBJECTS = \
"CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o" \
"CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o" \
"CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o" \
"CMakeFiles/directionality_01.dir/MCParticle.cpp.o" \
"CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o" \
"CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o" \
"CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o" \
"CMakeFiles/directionality_01.dir/RunAction.cpp.o" \
"CMakeFiles/directionality_01.dir/EventAction.cpp.o" \
"CMakeFiles/directionality_01.dir/SteppingAction.cpp.o" \
"CMakeFiles/directionality_01.dir/TrackingAction.cpp.o" \
"CMakeFiles/directionality_01.dir/TrackingSD.cpp.o" \
"CMakeFiles/directionality_01.dir/TrackingHit.cpp.o" \
"CMakeFiles/directionality_01.dir/Supernova.cpp.o" \
"CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o" \
"CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o"

# External object files for target directionality_01
directionality_01_EXTERNAL_OBJECTS =

src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/AnalysisManager.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/GeneratorParticle.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/MCTruthManager.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/MCParticle.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/DetectorConstruction.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/DetectorMessenger.cc.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/PrimaryGeneration.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/RunAction.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/EventAction.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/SteppingAction.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/TrackingAction.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/TrackingSD.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/TrackingHit.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/Supernova.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/SupernovaTiming.cpp.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/QPixG4Dict.cxx.o
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/build.make
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libCore.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libImt.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libRIO.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libNet.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libHist.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libGraf.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libGraf3d.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libGpad.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libROOTDataFrame.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libTree.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libTreePlayer.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libRint.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libPostscript.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libMatrix.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libPhysics.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libMathCore.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libThread.so
src/libdirectionality_01.so: /usr/local/root/6.18.04/lib/libMultiProc.so
src/libdirectionality_01.so: src/CMakeFiles/directionality_01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX shared library libdirectionality_01.so"
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/directionality_01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/directionality_01.dir/build: src/libdirectionality_01.so

.PHONY : src/CMakeFiles/directionality_01.dir/build

src/CMakeFiles/directionality_01.dir/clean:
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src && $(CMAKE_COMMAND) -P CMakeFiles/directionality_01.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/directionality_01.dir/clean

src/CMakeFiles/directionality_01.dir/depend: src/QPixG4Dict.cxx
src/CMakeFiles/directionality_01.dir/depend: src/libQPixG4Dict_rdict.pcm
src/CMakeFiles/directionality_01.dir/depend: src/libQPixG4Dict.rootmap
	cd /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/local1/Geant4_Project/Directionality-Project/electron_directionality /home/local1/Geant4_Project/Directionality-Project/electron_directionality/src /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src /home/local1/Geant4_Project/Directionality-Project/electron_directionality/Build/src/CMakeFiles/directionality_01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/directionality_01.dir/depend

