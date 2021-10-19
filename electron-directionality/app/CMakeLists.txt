## ---------------------------------------------------------
##  directionality01 | app/CMakeLists.txt
##
##  CMake build script.
##   * Author: Justo Martin-Albo
##   * Creation date: 14 Aug 2019
## ---------------------------------------------------------


add_executable(directionality01run directionality01.cc)
target_include_directories(directionality01run PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(directionality01run ${CMAKE_PROJECT_NAME} ${Geant4_LIBRARIES})

install(TARGETS directionality01run RUNTIME DESTINATION bin)
