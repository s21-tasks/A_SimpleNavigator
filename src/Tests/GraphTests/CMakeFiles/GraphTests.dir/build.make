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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests

# Include any dependencies generated for this target.
include CMakeFiles/GraphTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GraphTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphTests.dir/flags.make

CMakeFiles/GraphTests.dir/GraphTests.cc.o: CMakeFiles/GraphTests.dir/flags.make
CMakeFiles/GraphTests.dir/GraphTests.cc.o: GraphTests.cc
CMakeFiles/GraphTests.dir/GraphTests.cc.o: CMakeFiles/GraphTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GraphTests.dir/GraphTests.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GraphTests.dir/GraphTests.cc.o -MF CMakeFiles/GraphTests.dir/GraphTests.cc.o.d -o CMakeFiles/GraphTests.dir/GraphTests.cc.o -c /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/GraphTests.cc

CMakeFiles/GraphTests.dir/GraphTests.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GraphTests.dir/GraphTests.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/GraphTests.cc > CMakeFiles/GraphTests.dir/GraphTests.cc.i

CMakeFiles/GraphTests.dir/GraphTests.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GraphTests.dir/GraphTests.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/GraphTests.cc -o CMakeFiles/GraphTests.dir/GraphTests.cc.s

# Object files for target GraphTests
GraphTests_OBJECTS = \
"CMakeFiles/GraphTests.dir/GraphTests.cc.o"

# External object files for target GraphTests
GraphTests_EXTERNAL_OBJECTS =

GraphTests: CMakeFiles/GraphTests.dir/GraphTests.cc.o
GraphTests: CMakeFiles/GraphTests.dir/build.make
GraphTests: Graph/s21_graph.a
GraphTests: matrix/matrix.a
GraphTests: utility/cpp_utilites.a
GraphTests: CMakeFiles/GraphTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GraphTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphTests.dir/build: GraphTests
.PHONY : CMakeFiles/GraphTests.dir/build

CMakeFiles/GraphTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphTests.dir/clean

CMakeFiles/GraphTests.dir/depend:
	cd /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests /Users/ivan/Projects/CPP/simplenavigator/src/Tests/GraphTests/CMakeFiles/GraphTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GraphTests.dir/depend

