# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vidd/Desktop/Grafi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vidd/Desktop/Grafi/build

# Include any dependencies generated for this target.
include test/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tests.dir/flags.make

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o: ../test/dfs_topological_sort_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vidd/Desktop/Grafi/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o"
	cd /home/vidd/Desktop/Grafi/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o -c /home/vidd/Desktop/Grafi/test/dfs_topological_sort_test.cpp

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.i"
	cd /home/vidd/Desktop/Grafi/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vidd/Desktop/Grafi/test/dfs_topological_sort_test.cpp > CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.i

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.s"
	cd /home/vidd/Desktop/Grafi/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vidd/Desktop/Grafi/test/dfs_topological_sort_test.cpp -o CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.s

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.requires:
.PHONY : test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.requires

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.provides: test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/tests.dir/build.make test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.provides

test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.provides.build: test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

../bin/tests: test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o
../bin/tests: test/CMakeFiles/tests.dir/build.make
../bin/tests: ../lib/libgrafi.a
../bin/tests: ../lib/libgtest.a
../bin/tests: ../lib/libgtest_main.a
../bin/tests: ../lib/libgtest.a
../bin/tests: test/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/tests"
	cd /home/vidd/Desktop/Grafi/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/tests.dir/build: ../bin/tests
.PHONY : test/CMakeFiles/tests.dir/build

test/CMakeFiles/tests.dir/requires: test/CMakeFiles/tests.dir/dfs_topological_sort_test.cpp.o.requires
.PHONY : test/CMakeFiles/tests.dir/requires

test/CMakeFiles/tests.dir/clean:
	cd /home/vidd/Desktop/Grafi/build/test && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/tests.dir/clean

test/CMakeFiles/tests.dir/depend:
	cd /home/vidd/Desktop/Grafi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vidd/Desktop/Grafi /home/vidd/Desktop/Grafi/test /home/vidd/Desktop/Grafi/build /home/vidd/Desktop/Grafi/build/test /home/vidd/Desktop/Grafi/build/test/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tests.dir/depend

