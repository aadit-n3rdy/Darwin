# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = /home/n3rdy/dev/cpp/Darwin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/n3rdy/dev/cpp/Darwin

# Include any dependencies generated for this target.
include CMakeFiles/Darwin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Darwin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Darwin.dir/flags.make

CMakeFiles/Darwin.dir/Darwin/main.cpp.o: CMakeFiles/Darwin.dir/flags.make
CMakeFiles/Darwin.dir/Darwin/main.cpp.o: Darwin/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/n3rdy/dev/cpp/Darwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Darwin.dir/Darwin/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Darwin.dir/Darwin/main.cpp.o -c /home/n3rdy/dev/cpp/Darwin/Darwin/main.cpp

CMakeFiles/Darwin.dir/Darwin/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Darwin.dir/Darwin/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/n3rdy/dev/cpp/Darwin/Darwin/main.cpp > CMakeFiles/Darwin.dir/Darwin/main.cpp.i

CMakeFiles/Darwin.dir/Darwin/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Darwin.dir/Darwin/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/n3rdy/dev/cpp/Darwin/Darwin/main.cpp -o CMakeFiles/Darwin.dir/Darwin/main.cpp.s

CMakeFiles/Darwin.dir/Deb/deb.cpp.o: CMakeFiles/Darwin.dir/flags.make
CMakeFiles/Darwin.dir/Deb/deb.cpp.o: Deb/deb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/n3rdy/dev/cpp/Darwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Darwin.dir/Deb/deb.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Darwin.dir/Deb/deb.cpp.o -c /home/n3rdy/dev/cpp/Darwin/Deb/deb.cpp

CMakeFiles/Darwin.dir/Deb/deb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Darwin.dir/Deb/deb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/n3rdy/dev/cpp/Darwin/Deb/deb.cpp > CMakeFiles/Darwin.dir/Deb/deb.cpp.i

CMakeFiles/Darwin.dir/Deb/deb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Darwin.dir/Deb/deb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/n3rdy/dev/cpp/Darwin/Deb/deb.cpp -o CMakeFiles/Darwin.dir/Deb/deb.cpp.s

# Object files for target Darwin
Darwin_OBJECTS = \
"CMakeFiles/Darwin.dir/Darwin/main.cpp.o" \
"CMakeFiles/Darwin.dir/Deb/deb.cpp.o"

# External object files for target Darwin
Darwin_EXTERNAL_OBJECTS =

Darwin: CMakeFiles/Darwin.dir/Darwin/main.cpp.o
Darwin: CMakeFiles/Darwin.dir/Deb/deb.cpp.o
Darwin: CMakeFiles/Darwin.dir/build.make
Darwin: N3rdNEAT/libN3rdNEAT.a
Darwin: CMakeFiles/Darwin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/n3rdy/dev/cpp/Darwin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Darwin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Darwin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Darwin.dir/build: Darwin

.PHONY : CMakeFiles/Darwin.dir/build

CMakeFiles/Darwin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Darwin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Darwin.dir/clean

CMakeFiles/Darwin.dir/depend:
	cd /home/n3rdy/dev/cpp/Darwin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/n3rdy/dev/cpp/Darwin /home/n3rdy/dev/cpp/Darwin /home/n3rdy/dev/cpp/Darwin /home/n3rdy/dev/cpp/Darwin /home/n3rdy/dev/cpp/Darwin/CMakeFiles/Darwin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Darwin.dir/depend

