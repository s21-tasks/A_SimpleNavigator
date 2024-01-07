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
CMAKE_SOURCE_DIR = /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build

# Include any dependencies generated for this target.
include CMakeFiles/s21_graph_algorithms.a.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/s21_graph_algorithms.a.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/s21_graph_algorithms.a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s21_graph_algorithms.a.dir/flags.make

CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o: CMakeFiles/s21_graph_algorithms.a.dir/flags.make
CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o: /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/GraphAlgorithms.cc
CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o: CMakeFiles/s21_graph_algorithms.a.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o -MF CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o.d -o CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o -c /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/GraphAlgorithms.cc

CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/GraphAlgorithms.cc > CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.i

CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/GraphAlgorithms.cc -o CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.s

# Object files for target s21_graph_algorithms.a
s21_graph_algorithms_a_OBJECTS = \
"CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o"

# External object files for target s21_graph_algorithms.a
s21_graph_algorithms_a_EXTERNAL_OBJECTS =

s21_graph_algorithms.a: CMakeFiles/s21_graph_algorithms.a.dir/GraphAlgorithms.cc.o
s21_graph_algorithms.a: CMakeFiles/s21_graph_algorithms.a.dir/build.make
s21_graph_algorithms.a: CMakeFiles/s21_graph_algorithms.a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library s21_graph_algorithms.a"
	$(CMAKE_COMMAND) -P CMakeFiles/s21_graph_algorithms.a.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/s21_graph_algorithms.a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s21_graph_algorithms.a.dir/build: s21_graph_algorithms.a
.PHONY : CMakeFiles/s21_graph_algorithms.a.dir/build

CMakeFiles/s21_graph_algorithms.a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s21_graph_algorithms.a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s21_graph_algorithms.a.dir/clean

CMakeFiles/s21_graph_algorithms.a.dir/depend:
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/CMakeFiles/s21_graph_algorithms.a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s21_graph_algorithms.a.dir/depend

