# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sfml_pathFinder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_pathFinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_pathFinder.dir/flags.make

CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o: CMakeFiles/sfml_pathFinder.dir/flags.make
CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o -c /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/src/main.cpp

CMakeFiles/sfml_pathFinder.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_pathFinder.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/src/main.cpp > CMakeFiles/sfml_pathFinder.dir/src/main.cpp.i

CMakeFiles/sfml_pathFinder.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_pathFinder.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/src/main.cpp -o CMakeFiles/sfml_pathFinder.dir/src/main.cpp.s

# Object files for target sfml_pathFinder
sfml_pathFinder_OBJECTS = \
"CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o"

# External object files for target sfml_pathFinder
sfml_pathFinder_EXTERNAL_OBJECTS =

sfml_pathFinder: CMakeFiles/sfml_pathFinder.dir/src/main.cpp.o
sfml_pathFinder: CMakeFiles/sfml_pathFinder.dir/build.make
sfml_pathFinder: /usr/local/lib/libsfml-network.dylib
sfml_pathFinder: /usr/local/lib/libsfml-audio.dylib
sfml_pathFinder: /usr/local/lib/libsfml-graphics.dylib
sfml_pathFinder: /usr/local/lib/libsfml-window.dylib
sfml_pathFinder: /usr/local/lib/libsfml-system.dylib
sfml_pathFinder: CMakeFiles/sfml_pathFinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sfml_pathFinder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_pathFinder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_pathFinder.dir/build: sfml_pathFinder

.PHONY : CMakeFiles/sfml_pathFinder.dir/build

CMakeFiles/sfml_pathFinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_pathFinder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_pathFinder.dir/clean

CMakeFiles/sfml_pathFinder.dir/depend:
	cd /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug /Users/lutrarutra/Documents/dev/sfml_projects/sfml_pathFinder/cmake-build-debug/CMakeFiles/sfml_pathFinder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml_pathFinder.dir/depend

