# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/joel/Programming/Repositories/6502-Emulator/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joel/Programming/Repositories/6502-Emulator/tests

# Include any dependencies generated for this target.
include CMakeFiles/test_CPU6502.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_CPU6502.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_CPU6502.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_CPU6502.dir/flags.make

CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o: CMakeFiles/test_CPU6502.dir/flags.make
CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o: test_CPU6502.cpp
CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o: CMakeFiles/test_CPU6502.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joel/Programming/Repositories/6502-Emulator/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o -MF CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o.d -o CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o -c /home/joel/Programming/Repositories/6502-Emulator/tests/test_CPU6502.cpp

CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joel/Programming/Repositories/6502-Emulator/tests/test_CPU6502.cpp > CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.i

CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joel/Programming/Repositories/6502-Emulator/tests/test_CPU6502.cpp -o CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.s

# Object files for target test_CPU6502
test_CPU6502_OBJECTS = \
"CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o"

# External object files for target test_CPU6502
test_CPU6502_EXTERNAL_OBJECTS =

test_CPU6502: CMakeFiles/test_CPU6502.dir/test_CPU6502.cpp.o
test_CPU6502: CMakeFiles/test_CPU6502.dir/build.make
test_CPU6502: CMakeFiles/test_CPU6502.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joel/Programming/Repositories/6502-Emulator/tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_CPU6502"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_CPU6502.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_CPU6502.dir/build: test_CPU6502
.PHONY : CMakeFiles/test_CPU6502.dir/build

CMakeFiles/test_CPU6502.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_CPU6502.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_CPU6502.dir/clean

CMakeFiles/test_CPU6502.dir/depend:
	cd /home/joel/Programming/Repositories/6502-Emulator/tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joel/Programming/Repositories/6502-Emulator/tests /home/joel/Programming/Repositories/6502-Emulator/tests /home/joel/Programming/Repositories/6502-Emulator/tests /home/joel/Programming/Repositories/6502-Emulator/tests /home/joel/Programming/Repositories/6502-Emulator/tests/CMakeFiles/test_CPU6502.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_CPU6502.dir/depend
