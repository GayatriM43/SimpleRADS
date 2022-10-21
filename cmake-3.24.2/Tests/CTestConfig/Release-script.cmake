set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_CMAKE_GENERATOR_PLATFORM "")
set(CTEST_CMAKE_GENERATOR_TOOLSET "")
set(CTEST_SOURCE_DIRECTORY "/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Tests/CTestConfig")
set(CTEST_BINARY_DIRECTORY "/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Tests/CTestConfig/Release-script")

ctest_start(Experimental)

set(_isMultiConfig "0")
if(_isMultiConfig)
  set(cfg_opts "-DCMAKE_CONFIGURATION_TYPES=Debug\\;Release\\;MinSizeRel\\;RelWithDebInfo")
else()
  set(cfg_opts)
endif()

ctest_configure(BUILD "${CTEST_BINARY_DIRECTORY}" OPTIONS "${cfg_opts}" RETURN_VALUE rv)
if(NOT rv STREQUAL 0)
  message(FATAL_ERROR "*** error in ctest_configure ***")
endif()

ctest_build(BUILD "${CTEST_BINARY_DIRECTORY}" RETURN_VALUE rv)
if(NOT rv STREQUAL 0)
  message(FATAL_ERROR "*** error in ctest_build ***")
endif()

ctest_test(BUILD "${CTEST_BINARY_DIRECTORY}" RETURN_VALUE rv)
if(NOT rv STREQUAL 0)
  message(FATAL_ERROR "*** error in ctest_test ***")
endif()
