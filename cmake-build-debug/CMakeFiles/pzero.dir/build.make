# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\adm\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.32\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\adm\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.32\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\adm\Documents\project\pzero

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\adm\Documents\project\pzero\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pzero.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pzero.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pzero.dir/flags.make

CMakeFiles/pzero.dir/main.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/main.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pzero.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\main.cpp.obj -c C:\Users\adm\Documents\project\pzero\main.cpp

CMakeFiles/pzero.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\main.cpp > CMakeFiles\pzero.dir\main.cpp.i

CMakeFiles/pzero.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\main.cpp -o CMakeFiles\pzero.dir\main.cpp.s

CMakeFiles/pzero.dir/engine/machine.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/engine/machine.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/engine/machine.cpp.obj: ../engine/machine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pzero.dir/engine/machine.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\engine\machine.cpp.obj -c C:\Users\adm\Documents\project\pzero\engine\machine.cpp

CMakeFiles/pzero.dir/engine/machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/engine/machine.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\engine\machine.cpp > CMakeFiles\pzero.dir\engine\machine.cpp.i

CMakeFiles/pzero.dir/engine/machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/engine/machine.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\engine\machine.cpp -o CMakeFiles\pzero.dir\engine\machine.cpp.s

CMakeFiles/pzero.dir/engine/input_manager.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/engine/input_manager.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/engine/input_manager.cpp.obj: ../engine/input_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pzero.dir/engine/input_manager.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\engine\input_manager.cpp.obj -c C:\Users\adm\Documents\project\pzero\engine\input_manager.cpp

CMakeFiles/pzero.dir/engine/input_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/engine/input_manager.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\engine\input_manager.cpp > CMakeFiles\pzero.dir\engine\input_manager.cpp.i

CMakeFiles/pzero.dir/engine/input_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/engine/input_manager.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\engine\input_manager.cpp -o CMakeFiles\pzero.dir\engine\input_manager.cpp.s

CMakeFiles/pzero.dir/state/splash_state.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/state/splash_state.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/state/splash_state.cpp.obj: ../state/splash_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pzero.dir/state/splash_state.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\state\splash_state.cpp.obj -c C:\Users\adm\Documents\project\pzero\state\splash_state.cpp

CMakeFiles/pzero.dir/state/splash_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/state/splash_state.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\state\splash_state.cpp > CMakeFiles\pzero.dir\state\splash_state.cpp.i

CMakeFiles/pzero.dir/state/splash_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/state/splash_state.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\state\splash_state.cpp -o CMakeFiles\pzero.dir\state\splash_state.cpp.s

CMakeFiles/pzero.dir/state/game.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/state/game.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/state/game.cpp.obj: ../state/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pzero.dir/state/game.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\state\game.cpp.obj -c C:\Users\adm\Documents\project\pzero\state\game.cpp

CMakeFiles/pzero.dir/state/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/state/game.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\state\game.cpp > CMakeFiles\pzero.dir\state\game.cpp.i

CMakeFiles/pzero.dir/state/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/state/game.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\state\game.cpp -o CMakeFiles\pzero.dir\state\game.cpp.s

CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj: ../state/main_menu_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\state\main_menu_state.cpp.obj -c C:\Users\adm\Documents\project\pzero\state\main_menu_state.cpp

CMakeFiles/pzero.dir/state/main_menu_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/state/main_menu_state.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\state\main_menu_state.cpp > CMakeFiles\pzero.dir\state\main_menu_state.cpp.i

CMakeFiles/pzero.dir/state/main_menu_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/state/main_menu_state.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\state\main_menu_state.cpp -o CMakeFiles\pzero.dir\state\main_menu_state.cpp.s

CMakeFiles/pzero.dir/state/game_arena.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/state/game_arena.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/state/game_arena.cpp.obj: ../state/game_arena.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pzero.dir/state/game_arena.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\state\game_arena.cpp.obj -c C:\Users\adm\Documents\project\pzero\state\game_arena.cpp

CMakeFiles/pzero.dir/state/game_arena.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/state/game_arena.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\state\game_arena.cpp > CMakeFiles\pzero.dir\state\game_arena.cpp.i

CMakeFiles/pzero.dir/state/game_arena.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/state/game_arena.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\state\game_arena.cpp -o CMakeFiles\pzero.dir\state\game_arena.cpp.s

CMakeFiles/pzero.dir/state/pause_state.cpp.obj: CMakeFiles/pzero.dir/flags.make
CMakeFiles/pzero.dir/state/pause_state.cpp.obj: CMakeFiles/pzero.dir/includes_CXX.rsp
CMakeFiles/pzero.dir/state/pause_state.cpp.obj: ../state/pause_state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pzero.dir/state/pause_state.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pzero.dir\state\pause_state.cpp.obj -c C:\Users\adm\Documents\project\pzero\state\pause_state.cpp

CMakeFiles/pzero.dir/state/pause_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pzero.dir/state/pause_state.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\adm\Documents\project\pzero\state\pause_state.cpp > CMakeFiles\pzero.dir\state\pause_state.cpp.i

CMakeFiles/pzero.dir/state/pause_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pzero.dir/state/pause_state.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\adm\Documents\project\pzero\state\pause_state.cpp -o CMakeFiles\pzero.dir\state\pause_state.cpp.s

# Object files for target pzero
pzero_OBJECTS = \
"CMakeFiles/pzero.dir/main.cpp.obj" \
"CMakeFiles/pzero.dir/engine/machine.cpp.obj" \
"CMakeFiles/pzero.dir/engine/input_manager.cpp.obj" \
"CMakeFiles/pzero.dir/state/splash_state.cpp.obj" \
"CMakeFiles/pzero.dir/state/game.cpp.obj" \
"CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj" \
"CMakeFiles/pzero.dir/state/game_arena.cpp.obj" \
"CMakeFiles/pzero.dir/state/pause_state.cpp.obj"

# External object files for target pzero
pzero_EXTERNAL_OBJECTS =

pzero.exe: CMakeFiles/pzero.dir/main.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/engine/machine.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/engine/input_manager.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/state/splash_state.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/state/game.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/state/main_menu_state.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/state/game_arena.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/state/pause_state.cpp.obj
pzero.exe: CMakeFiles/pzero.dir/build.make
pzero.exe: CMakeFiles/pzero.dir/linklibs.rsp
pzero.exe: CMakeFiles/pzero.dir/objects1.rsp
pzero.exe: CMakeFiles/pzero.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable pzero.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pzero.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pzero.dir/build: pzero.exe

.PHONY : CMakeFiles/pzero.dir/build

CMakeFiles/pzero.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pzero.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pzero.dir/clean

CMakeFiles/pzero.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\adm\Documents\project\pzero C:\Users\adm\Documents\project\pzero C:\Users\adm\Documents\project\pzero\cmake-build-debug C:\Users\adm\Documents\project\pzero\cmake-build-debug C:\Users\adm\Documents\project\pzero\cmake-build-debug\CMakeFiles\pzero.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pzero.dir/depend

