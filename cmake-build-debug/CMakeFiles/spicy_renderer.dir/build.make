# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uberdever/dev/PRJS/spicy_renderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spicy_renderer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/spicy_renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spicy_renderer.dir/flags.make

CMakeFiles/spicy_renderer.dir/sandbox/main.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/main.c.o: ../sandbox/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/main.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/main.c

CMakeFiles/spicy_renderer.dir/sandbox/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/main.c > CMakeFiles/spicy_renderer.dir/sandbox/main.c.i

CMakeFiles/spicy_renderer.dir/sandbox/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/main.c -o CMakeFiles/spicy_renderer.dir/sandbox/main.c.s

CMakeFiles/spicy_renderer.dir/src/alpha.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/src/alpha.c.o: ../src/alpha.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/spicy_renderer.dir/src/alpha.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/src/alpha.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/src/alpha.c

CMakeFiles/spicy_renderer.dir/src/alpha.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/src/alpha.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/src/alpha.c > CMakeFiles/spicy_renderer.dir/src/alpha.c.i

CMakeFiles/spicy_renderer.dir/src/alpha.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/src/alpha.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/src/alpha.c -o CMakeFiles/spicy_renderer.dir/src/alpha.c.s

CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o: ../src/alphabeta.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/src/alphabeta.c

CMakeFiles/spicy_renderer.dir/src/alphabeta.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/src/alphabeta.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/src/alphabeta.c > CMakeFiles/spicy_renderer.dir/src/alphabeta.c.i

CMakeFiles/spicy_renderer.dir/src/alphabeta.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/src/alphabeta.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/src/alphabeta.c -o CMakeFiles/spicy_renderer.dir/src/alphabeta.c.s

CMakeFiles/spicy_renderer.dir/src/gamma.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/src/gamma.c.o: ../src/gamma.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/spicy_renderer.dir/src/gamma.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/src/gamma.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/src/gamma.c

CMakeFiles/spicy_renderer.dir/src/gamma.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/src/gamma.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/src/gamma.c > CMakeFiles/spicy_renderer.dir/src/gamma.c.i

CMakeFiles/spicy_renderer.dir/src/gamma.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/src/gamma.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/src/gamma.c -o CMakeFiles/spicy_renderer.dir/src/gamma.c.s

CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o: ../sandbox/scenes/cube.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/cube.c

CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/cube.c > CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.i

CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/cube.c -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.s

CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o: ../src/gamma/alphabet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/src/gamma/alphabet.c

CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/src/gamma/alphabet.c > CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.i

CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/src/gamma/alphabet.c -o CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.s

CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o: ../sandbox/scenes/star.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/star.c

CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/star.c > CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.i

CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/star.c -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.s

CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o: ../sandbox/scenes/triangle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/triangle.c

CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/triangle.c > CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.i

CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/triangle.c -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.s

CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o: ../sandbox/pipeline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/pipeline.c

CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/pipeline.c > CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.i

CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/pipeline.c -o CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.s

CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o: CMakeFiles/spicy_renderer.dir/flags.make
CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o: ../sandbox/scenes/quad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o   -c /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/quad.c

CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/quad.c > CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.i

CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/uberdever/dev/PRJS/spicy_renderer/sandbox/scenes/quad.c -o CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.s

# Object files for target spicy_renderer
spicy_renderer_OBJECTS = \
"CMakeFiles/spicy_renderer.dir/sandbox/main.c.o" \
"CMakeFiles/spicy_renderer.dir/src/alpha.c.o" \
"CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o" \
"CMakeFiles/spicy_renderer.dir/src/gamma.c.o" \
"CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o" \
"CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o" \
"CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o" \
"CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o" \
"CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o" \
"CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o"

# External object files for target spicy_renderer
spicy_renderer_EXTERNAL_OBJECTS =

spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/main.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/src/alpha.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/src/alphabeta.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/src/gamma.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/scenes/cube.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/src/gamma/alphabet.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/scenes/star.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/scenes/triangle.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/pipeline.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/sandbox/scenes/quad.c.o
spicy_renderer: CMakeFiles/spicy_renderer.dir/build.make
spicy_renderer: /usr/lib/x86_64-linux-gnu/libSDL2main.a
spicy_renderer: /usr/lib/x86_64-linux-gnu/libSDL2.so
spicy_renderer: /usr/lib/x86_64-linux-gnu/libSDL2_image.so
spicy_renderer: /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so
spicy_renderer: /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so
spicy_renderer: CMakeFiles/spicy_renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable spicy_renderer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spicy_renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spicy_renderer.dir/build: spicy_renderer

.PHONY : CMakeFiles/spicy_renderer.dir/build

CMakeFiles/spicy_renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spicy_renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spicy_renderer.dir/clean

CMakeFiles/spicy_renderer.dir/depend:
	cd /home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uberdever/dev/PRJS/spicy_renderer /home/uberdever/dev/PRJS/spicy_renderer /home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug /home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug /home/uberdever/dev/PRJS/spicy_renderer/cmake-build-debug/CMakeFiles/spicy_renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spicy_renderer.dir/depend
