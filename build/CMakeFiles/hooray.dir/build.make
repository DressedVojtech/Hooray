# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = /home/vk/dev/cpp/hooray5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vk/dev/cpp/hooray5/build

# Include any dependencies generated for this target.
include CMakeFiles/hooray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hooray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hooray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hooray.dir/flags.make

CMakeFiles/hooray.dir/main.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/main.cpp.o: /home/vk/dev/cpp/hooray5/main.cpp
CMakeFiles/hooray.dir/main.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hooray.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/main.cpp.o -MF CMakeFiles/hooray.dir/main.cpp.o.d -o CMakeFiles/hooray.dir/main.cpp.o -c /home/vk/dev/cpp/hooray5/main.cpp

CMakeFiles/hooray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/main.cpp > CMakeFiles/hooray.dir/main.cpp.i

CMakeFiles/hooray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/main.cpp -o CMakeFiles/hooray.dir/main.cpp.s

CMakeFiles/hooray.dir/src/light_source.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/light_source.cpp.o: /home/vk/dev/cpp/hooray5/src/light_source.cpp
CMakeFiles/hooray.dir/src/light_source.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hooray.dir/src/light_source.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/light_source.cpp.o -MF CMakeFiles/hooray.dir/src/light_source.cpp.o.d -o CMakeFiles/hooray.dir/src/light_source.cpp.o -c /home/vk/dev/cpp/hooray5/src/light_source.cpp

CMakeFiles/hooray.dir/src/light_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/light_source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/light_source.cpp > CMakeFiles/hooray.dir/src/light_source.cpp.i

CMakeFiles/hooray.dir/src/light_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/light_source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/light_source.cpp -o CMakeFiles/hooray.dir/src/light_source.cpp.s

CMakeFiles/hooray.dir/src/object.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/object.cpp.o: /home/vk/dev/cpp/hooray5/src/object.cpp
CMakeFiles/hooray.dir/src/object.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hooray.dir/src/object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/object.cpp.o -MF CMakeFiles/hooray.dir/src/object.cpp.o.d -o CMakeFiles/hooray.dir/src/object.cpp.o -c /home/vk/dev/cpp/hooray5/src/object.cpp

CMakeFiles/hooray.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/object.cpp > CMakeFiles/hooray.dir/src/object.cpp.i

CMakeFiles/hooray.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/object.cpp -o CMakeFiles/hooray.dir/src/object.cpp.s

CMakeFiles/hooray.dir/src/ray.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/ray.cpp.o: /home/vk/dev/cpp/hooray5/src/ray.cpp
CMakeFiles/hooray.dir/src/ray.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hooray.dir/src/ray.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/ray.cpp.o -MF CMakeFiles/hooray.dir/src/ray.cpp.o.d -o CMakeFiles/hooray.dir/src/ray.cpp.o -c /home/vk/dev/cpp/hooray5/src/ray.cpp

CMakeFiles/hooray.dir/src/ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/ray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/ray.cpp > CMakeFiles/hooray.dir/src/ray.cpp.i

CMakeFiles/hooray.dir/src/ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/ray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/ray.cpp -o CMakeFiles/hooray.dir/src/ray.cpp.s

CMakeFiles/hooray.dir/src/rgb.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/rgb.cpp.o: /home/vk/dev/cpp/hooray5/src/rgb.cpp
CMakeFiles/hooray.dir/src/rgb.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hooray.dir/src/rgb.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/rgb.cpp.o -MF CMakeFiles/hooray.dir/src/rgb.cpp.o.d -o CMakeFiles/hooray.dir/src/rgb.cpp.o -c /home/vk/dev/cpp/hooray5/src/rgb.cpp

CMakeFiles/hooray.dir/src/rgb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/rgb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/rgb.cpp > CMakeFiles/hooray.dir/src/rgb.cpp.i

CMakeFiles/hooray.dir/src/rgb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/rgb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/rgb.cpp -o CMakeFiles/hooray.dir/src/rgb.cpp.s

CMakeFiles/hooray.dir/src/scene.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/scene.cpp.o: /home/vk/dev/cpp/hooray5/src/scene.cpp
CMakeFiles/hooray.dir/src/scene.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hooray.dir/src/scene.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/scene.cpp.o -MF CMakeFiles/hooray.dir/src/scene.cpp.o.d -o CMakeFiles/hooray.dir/src/scene.cpp.o -c /home/vk/dev/cpp/hooray5/src/scene.cpp

CMakeFiles/hooray.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/scene.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/scene.cpp > CMakeFiles/hooray.dir/src/scene.cpp.i

CMakeFiles/hooray.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/scene.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/scene.cpp -o CMakeFiles/hooray.dir/src/scene.cpp.s

CMakeFiles/hooray.dir/src/triangle.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/triangle.cpp.o: /home/vk/dev/cpp/hooray5/src/triangle.cpp
CMakeFiles/hooray.dir/src/triangle.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hooray.dir/src/triangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/triangle.cpp.o -MF CMakeFiles/hooray.dir/src/triangle.cpp.o.d -o CMakeFiles/hooray.dir/src/triangle.cpp.o -c /home/vk/dev/cpp/hooray5/src/triangle.cpp

CMakeFiles/hooray.dir/src/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/triangle.cpp > CMakeFiles/hooray.dir/src/triangle.cpp.i

CMakeFiles/hooray.dir/src/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/triangle.cpp -o CMakeFiles/hooray.dir/src/triangle.cpp.s

CMakeFiles/hooray.dir/src/vec2.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/vec2.cpp.o: /home/vk/dev/cpp/hooray5/src/vec2.cpp
CMakeFiles/hooray.dir/src/vec2.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/hooray.dir/src/vec2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/vec2.cpp.o -MF CMakeFiles/hooray.dir/src/vec2.cpp.o.d -o CMakeFiles/hooray.dir/src/vec2.cpp.o -c /home/vk/dev/cpp/hooray5/src/vec2.cpp

CMakeFiles/hooray.dir/src/vec2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/vec2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/vec2.cpp > CMakeFiles/hooray.dir/src/vec2.cpp.i

CMakeFiles/hooray.dir/src/vec2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/vec2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/vec2.cpp -o CMakeFiles/hooray.dir/src/vec2.cpp.s

CMakeFiles/hooray.dir/src/vec3.cpp.o: CMakeFiles/hooray.dir/flags.make
CMakeFiles/hooray.dir/src/vec3.cpp.o: /home/vk/dev/cpp/hooray5/src/vec3.cpp
CMakeFiles/hooray.dir/src/vec3.cpp.o: CMakeFiles/hooray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/hooray.dir/src/vec3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hooray.dir/src/vec3.cpp.o -MF CMakeFiles/hooray.dir/src/vec3.cpp.o.d -o CMakeFiles/hooray.dir/src/vec3.cpp.o -c /home/vk/dev/cpp/hooray5/src/vec3.cpp

CMakeFiles/hooray.dir/src/vec3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hooray.dir/src/vec3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vk/dev/cpp/hooray5/src/vec3.cpp > CMakeFiles/hooray.dir/src/vec3.cpp.i

CMakeFiles/hooray.dir/src/vec3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hooray.dir/src/vec3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vk/dev/cpp/hooray5/src/vec3.cpp -o CMakeFiles/hooray.dir/src/vec3.cpp.s

# Object files for target hooray
hooray_OBJECTS = \
"CMakeFiles/hooray.dir/main.cpp.o" \
"CMakeFiles/hooray.dir/src/light_source.cpp.o" \
"CMakeFiles/hooray.dir/src/object.cpp.o" \
"CMakeFiles/hooray.dir/src/ray.cpp.o" \
"CMakeFiles/hooray.dir/src/rgb.cpp.o" \
"CMakeFiles/hooray.dir/src/scene.cpp.o" \
"CMakeFiles/hooray.dir/src/triangle.cpp.o" \
"CMakeFiles/hooray.dir/src/vec2.cpp.o" \
"CMakeFiles/hooray.dir/src/vec3.cpp.o"

# External object files for target hooray
hooray_EXTERNAL_OBJECTS =

hooray: CMakeFiles/hooray.dir/main.cpp.o
hooray: CMakeFiles/hooray.dir/src/light_source.cpp.o
hooray: CMakeFiles/hooray.dir/src/object.cpp.o
hooray: CMakeFiles/hooray.dir/src/ray.cpp.o
hooray: CMakeFiles/hooray.dir/src/rgb.cpp.o
hooray: CMakeFiles/hooray.dir/src/scene.cpp.o
hooray: CMakeFiles/hooray.dir/src/triangle.cpp.o
hooray: CMakeFiles/hooray.dir/src/vec2.cpp.o
hooray: CMakeFiles/hooray.dir/src/vec3.cpp.o
hooray: CMakeFiles/hooray.dir/build.make
hooray: /usr/lib/libSDL2main.a
hooray: /usr/lib/libSDL2-2.0.so.0.2400.0
hooray: CMakeFiles/hooray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vk/dev/cpp/hooray5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable hooray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hooray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hooray.dir/build: hooray
.PHONY : CMakeFiles/hooray.dir/build

CMakeFiles/hooray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hooray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hooray.dir/clean

CMakeFiles/hooray.dir/depend:
	cd /home/vk/dev/cpp/hooray5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vk/dev/cpp/hooray5 /home/vk/dev/cpp/hooray5 /home/vk/dev/cpp/hooray5/build /home/vk/dev/cpp/hooray5/build /home/vk/dev/cpp/hooray5/build/CMakeFiles/hooray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hooray.dir/depend

