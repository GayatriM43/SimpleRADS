# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Bootstrap.cmk/cmake

# The command to remove a file.
RM = /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Bootstrap.cmk/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2

# Include any dependencies generated for this target.
include Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/compiler_depend.make

# Include the progress variables for this target.
include Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/progress.make

# Include the compile flags for this target's objects.
include Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/flags.make

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/flags.make
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o: Utilities/cmjsoncpp/src/lib_json/json_reader.cpp
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o -MF CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o.d -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_reader.cpp

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_reader.cpp > CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.i

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_reader.cpp -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.s

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/flags.make
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o: Utilities/cmjsoncpp/src/lib_json/json_value.cpp
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o -MF CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o.d -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_value.cpp

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_value.cpp > CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.i

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_value.cpp -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.s

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/flags.make
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o: Utilities/cmjsoncpp/src/lib_json/json_writer.cpp
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o -MF CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o.d -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_writer.cpp

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_writer.cpp > CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.i

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/src/lib_json/json_writer.cpp -o CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.s

# Object files for target cmjsoncpp
cmjsoncpp_OBJECTS = \
"CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o" \
"CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o" \
"CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o"

# External object files for target cmjsoncpp
cmjsoncpp_EXTERNAL_OBJECTS =

Utilities/cmjsoncpp/libcmjsoncpp.a: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_reader.cpp.o
Utilities/cmjsoncpp/libcmjsoncpp.a: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_value.cpp.o
Utilities/cmjsoncpp/libcmjsoncpp.a: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/src/lib_json/json_writer.cpp.o
Utilities/cmjsoncpp/libcmjsoncpp.a: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/build.make
Utilities/cmjsoncpp/libcmjsoncpp.a: Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libcmjsoncpp.a"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && $(CMAKE_COMMAND) -P CMakeFiles/cmjsoncpp.dir/cmake_clean_target.cmake
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmjsoncpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/build: Utilities/cmjsoncpp/libcmjsoncpp.a
.PHONY : Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/build

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/clean:
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp && $(CMAKE_COMMAND) -P CMakeFiles/cmjsoncpp.dir/cmake_clean.cmake
.PHONY : Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/clean

Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/depend:
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Utilities/cmjsoncpp/CMakeFiles/cmjsoncpp.dir/depend

