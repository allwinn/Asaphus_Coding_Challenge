# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build"

# Include any dependencies generated for this target.
include CMakeFiles/challenge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/challenge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/challenge.dir/flags.make

CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o: CMakeFiles/challenge.dir/flags.make
CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o: ../asaphus_coding_challenge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o -c "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/asaphus_coding_challenge.cpp"

CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/asaphus_coding_challenge.cpp" > CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.i

CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/asaphus_coding_challenge.cpp" -o CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.s

# Object files for target challenge
challenge_OBJECTS = \
"CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o"

# External object files for target challenge
challenge_EXTERNAL_OBJECTS =

challenge: CMakeFiles/challenge.dir/asaphus_coding_challenge.cpp.o
challenge: CMakeFiles/challenge.dir/build.make
challenge: CMakeFiles/challenge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable challenge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/challenge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/challenge.dir/build: challenge

.PHONY : CMakeFiles/challenge.dir/build

CMakeFiles/challenge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/challenge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/challenge.dir/clean

CMakeFiles/challenge.dir/depend:
	cd "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge" "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge" "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build" "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build" "/home/allwin/Projects/Asaphus_Coding_Challenge/asaphus_coding_challenge - Allwin/Asaphus_Coding_Submission/Asaphus_Coding_Challenge/build/CMakeFiles/challenge.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/challenge.dir/depend
