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
include utility/CMakeFiles/utility.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include utility/CMakeFiles/utility.dir/compiler_depend.make

# Include the progress variables for this target.
include utility/CMakeFiles/utility.dir/progress.make

# Include the compile flags for this target's objects.
include utility/CMakeFiles/utility.dir/flags.make

utility/CMakeFiles/utility.dir/dummy.cc.o: utility/CMakeFiles/utility.dir/flags.make
utility/CMakeFiles/utility.dir/dummy.cc.o: /Users/ivan/Projects/CPP/simplenavigator/src/submodules/cpp_libs/utility/dummy.cc
utility/CMakeFiles/utility.dir/dummy.cc.o: utility/CMakeFiles/utility.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utility/CMakeFiles/utility.dir/dummy.cc.o"
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utility/CMakeFiles/utility.dir/dummy.cc.o -MF CMakeFiles/utility.dir/dummy.cc.o.d -o CMakeFiles/utility.dir/dummy.cc.o -c /Users/ivan/Projects/CPP/simplenavigator/src/submodules/cpp_libs/utility/dummy.cc

utility/CMakeFiles/utility.dir/dummy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utility.dir/dummy.cc.i"
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivan/Projects/CPP/simplenavigator/src/submodules/cpp_libs/utility/dummy.cc > CMakeFiles/utility.dir/dummy.cc.i

utility/CMakeFiles/utility.dir/dummy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utility.dir/dummy.cc.s"
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivan/Projects/CPP/simplenavigator/src/submodules/cpp_libs/utility/dummy.cc -o CMakeFiles/utility.dir/dummy.cc.s

# Object files for target utility
utility_OBJECTS = \
"CMakeFiles/utility.dir/dummy.cc.o"

# External object files for target utility
utility_EXTERNAL_OBJECTS =

utility/cpp_utilites.a: utility/CMakeFiles/utility.dir/dummy.cc.o
utility/cpp_utilites.a: utility/CMakeFiles/utility.dir/build.make
utility/cpp_utilites.a: utility/CMakeFiles/utility.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library cpp_utilites.a"
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && $(CMAKE_COMMAND) -P CMakeFiles/utility.dir/cmake_clean_target.cmake
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utility.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utility/CMakeFiles/utility.dir/build: utility/cpp_utilites.a
.PHONY : utility/CMakeFiles/utility.dir/build

utility/CMakeFiles/utility.dir/clean:
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility && $(CMAKE_COMMAND) -P CMakeFiles/utility.dir/cmake_clean.cmake
.PHONY : utility/CMakeFiles/utility.dir/clean

utility/CMakeFiles/utility.dir/depend:
	cd /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms /Users/ivan/Projects/CPP/simplenavigator/src/submodules/cpp_libs/utility /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility /Users/ivan/Projects/CPP/simplenavigator/src/GraphAlgorithms/build/utility/CMakeFiles/utility.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utility/CMakeFiles/utility.dir/depend

