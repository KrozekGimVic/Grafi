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
include src/CMakeFiles/grafi.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/grafi.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/grafi.dir/flags.make

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o: src/CMakeFiles/grafi.dir/flags.make
src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o: ../src/dfs_topological_sort.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vidd/Desktop/Grafi/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o"
	cd /home/vidd/Desktop/Grafi/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o -c /home/vidd/Desktop/Grafi/src/dfs_topological_sort.cpp

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/grafi.dir/dfs_topological_sort.cpp.i"
	cd /home/vidd/Desktop/Grafi/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/vidd/Desktop/Grafi/src/dfs_topological_sort.cpp > CMakeFiles/grafi.dir/dfs_topological_sort.cpp.i

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/grafi.dir/dfs_topological_sort.cpp.s"
	cd /home/vidd/Desktop/Grafi/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/vidd/Desktop/Grafi/src/dfs_topological_sort.cpp -o CMakeFiles/grafi.dir/dfs_topological_sort.cpp.s

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.requires:
.PHONY : src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.requires

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.provides: src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/grafi.dir/build.make src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.provides.build
.PHONY : src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.provides

src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.provides.build: src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o

# Object files for target grafi
grafi_OBJECTS = \
"CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o"

# External object files for target grafi
grafi_EXTERNAL_OBJECTS =

../lib/libgrafi.a: src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o
../lib/libgrafi.a: src/CMakeFiles/grafi.dir/build.make
../lib/libgrafi.a: src/CMakeFiles/grafi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libgrafi.a"
	cd /home/vidd/Desktop/Grafi/build/src && $(CMAKE_COMMAND) -P CMakeFiles/grafi.dir/cmake_clean_target.cmake
	cd /home/vidd/Desktop/Grafi/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/grafi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/grafi.dir/build: ../lib/libgrafi.a
.PHONY : src/CMakeFiles/grafi.dir/build

src/CMakeFiles/grafi.dir/requires: src/CMakeFiles/grafi.dir/dfs_topological_sort.cpp.o.requires
.PHONY : src/CMakeFiles/grafi.dir/requires

src/CMakeFiles/grafi.dir/clean:
	cd /home/vidd/Desktop/Grafi/build/src && $(CMAKE_COMMAND) -P CMakeFiles/grafi.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/grafi.dir/clean

src/CMakeFiles/grafi.dir/depend:
	cd /home/vidd/Desktop/Grafi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vidd/Desktop/Grafi /home/vidd/Desktop/Grafi/src /home/vidd/Desktop/Grafi/build /home/vidd/Desktop/Grafi/build/src /home/vidd/Desktop/Grafi/build/src/CMakeFiles/grafi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/grafi.dir/depend

