# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Code\BatailleNavale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Code\BatailleNavale\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BatailleNavale.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BatailleNavale.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BatailleNavale.dir/flags.make

CMakeFiles/BatailleNavale.dir/main.c.obj: CMakeFiles/BatailleNavale.dir/flags.make
CMakeFiles/BatailleNavale.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Code\BatailleNavale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BatailleNavale.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BatailleNavale.dir\main.c.obj   -c C:\Code\BatailleNavale\main.c

CMakeFiles/BatailleNavale.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BatailleNavale.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Code\BatailleNavale\main.c > CMakeFiles\BatailleNavale.dir\main.c.i

CMakeFiles/BatailleNavale.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BatailleNavale.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Code\BatailleNavale\main.c -o CMakeFiles\BatailleNavale.dir\main.c.s

# Object files for target BatailleNavale
BatailleNavale_OBJECTS = \
"CMakeFiles/BatailleNavale.dir/main.c.obj"

# External object files for target BatailleNavale
BatailleNavale_EXTERNAL_OBJECTS =

BatailleNavale.exe: CMakeFiles/BatailleNavale.dir/main.c.obj
BatailleNavale.exe: CMakeFiles/BatailleNavale.dir/build.make
BatailleNavale.exe: CMakeFiles/BatailleNavale.dir/linklibs.rsp
BatailleNavale.exe: CMakeFiles/BatailleNavale.dir/objects1.rsp
BatailleNavale.exe: CMakeFiles/BatailleNavale.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Code\BatailleNavale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BatailleNavale.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BatailleNavale.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BatailleNavale.dir/build: BatailleNavale.exe

.PHONY : CMakeFiles/BatailleNavale.dir/build

CMakeFiles/BatailleNavale.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BatailleNavale.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BatailleNavale.dir/clean

CMakeFiles/BatailleNavale.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Code\BatailleNavale C:\Code\BatailleNavale C:\Code\BatailleNavale\cmake-build-debug C:\Code\BatailleNavale\cmake-build-debug C:\Code\BatailleNavale\cmake-build-debug\CMakeFiles\BatailleNavale.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BatailleNavale.dir/depend

