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
include Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.make

# Include the progress variables for this target.
include Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/progress.make

# Include the compile flags for this target's objects.
include Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o: Utilities/cmbzip2/blocksort.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o -MF CMakeFiles/cmbzip2.dir/blocksort.c.o.d -o CMakeFiles/cmbzip2.dir/blocksort.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/blocksort.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/blocksort.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/blocksort.c > CMakeFiles/cmbzip2.dir/blocksort.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/blocksort.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/blocksort.c -o CMakeFiles/cmbzip2.dir/blocksort.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o: Utilities/cmbzip2/huffman.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o -MF CMakeFiles/cmbzip2.dir/huffman.c.o.d -o CMakeFiles/cmbzip2.dir/huffman.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/huffman.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/huffman.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/huffman.c > CMakeFiles/cmbzip2.dir/huffman.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/huffman.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/huffman.c -o CMakeFiles/cmbzip2.dir/huffman.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o: Utilities/cmbzip2/crctable.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o -MF CMakeFiles/cmbzip2.dir/crctable.c.o.d -o CMakeFiles/cmbzip2.dir/crctable.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/crctable.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/crctable.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/crctable.c > CMakeFiles/cmbzip2.dir/crctable.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/crctable.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/crctable.c -o CMakeFiles/cmbzip2.dir/crctable.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o: Utilities/cmbzip2/randtable.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o -MF CMakeFiles/cmbzip2.dir/randtable.c.o.d -o CMakeFiles/cmbzip2.dir/randtable.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/randtable.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/randtable.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/randtable.c > CMakeFiles/cmbzip2.dir/randtable.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/randtable.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/randtable.c -o CMakeFiles/cmbzip2.dir/randtable.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o: Utilities/cmbzip2/compress.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o -MF CMakeFiles/cmbzip2.dir/compress.c.o.d -o CMakeFiles/cmbzip2.dir/compress.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/compress.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/compress.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/compress.c > CMakeFiles/cmbzip2.dir/compress.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/compress.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/compress.c -o CMakeFiles/cmbzip2.dir/compress.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o: Utilities/cmbzip2/decompress.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o -MF CMakeFiles/cmbzip2.dir/decompress.c.o.d -o CMakeFiles/cmbzip2.dir/decompress.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/decompress.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/decompress.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/decompress.c > CMakeFiles/cmbzip2.dir/decompress.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/decompress.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/decompress.c -o CMakeFiles/cmbzip2.dir/decompress.c.s

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/flags.make
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o: Utilities/cmbzip2/bzlib.c
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o -MF CMakeFiles/cmbzip2.dir/bzlib.c.o.d -o CMakeFiles/cmbzip2.dir/bzlib.c.o -c /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/bzlib.c

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cmbzip2.dir/bzlib.c.i"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/bzlib.c > CMakeFiles/cmbzip2.dir/bzlib.c.i

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cmbzip2.dir/bzlib.c.s"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/bzlib.c -o CMakeFiles/cmbzip2.dir/bzlib.c.s

# Object files for target cmbzip2
cmbzip2_OBJECTS = \
"CMakeFiles/cmbzip2.dir/blocksort.c.o" \
"CMakeFiles/cmbzip2.dir/huffman.c.o" \
"CMakeFiles/cmbzip2.dir/crctable.c.o" \
"CMakeFiles/cmbzip2.dir/randtable.c.o" \
"CMakeFiles/cmbzip2.dir/compress.c.o" \
"CMakeFiles/cmbzip2.dir/decompress.c.o" \
"CMakeFiles/cmbzip2.dir/bzlib.c.o"

# External object files for target cmbzip2
cmbzip2_EXTERNAL_OBJECTS =

Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/blocksort.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/huffman.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/crctable.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/randtable.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/compress.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/decompress.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/bzlib.c.o
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/build.make
Utilities/cmbzip2/libcmbzip2.a: Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library libcmbzip2.a"
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && $(CMAKE_COMMAND) -P CMakeFiles/cmbzip2.dir/cmake_clean_target.cmake
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmbzip2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/build: Utilities/cmbzip2/libcmbzip2.a
.PHONY : Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/build

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/clean:
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 && $(CMAKE_COMMAND) -P CMakeFiles/cmbzip2.dir/cmake_clean.cmake
.PHONY : Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/clean

Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/depend:
	cd /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2 /home/administrator/gayatri/4_1/ds/phase-1-30/cmake-3.24.2/Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Utilities/cmbzip2/CMakeFiles/cmbzip2.dir/depend

