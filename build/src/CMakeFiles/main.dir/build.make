# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.1

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
CMAKE_SOURCE_DIR = /home/schoko/git/learningCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/schoko/git/learningCpp/build

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/main.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/schoko/git/learningCpp/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/main.dir/main.cpp.o"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/main.cpp.o -c /home/schoko/git/learningCpp/src/main.cpp

src/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/schoko/git/learningCpp/src/main.cpp > CMakeFiles/main.dir/main.cpp.i

src/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/schoko/git/learningCpp/src/main.cpp -o CMakeFiles/main.dir/main.cpp.s

src/CMakeFiles/main.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/main.dir/main.cpp.o.requires

src/CMakeFiles/main.dir/main.cpp.o.provides: src/CMakeFiles/main.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/main.cpp.o.provides

src/CMakeFiles/main.dir/main.cpp.o.provides.build: src/CMakeFiles/main.dir/main.cpp.o

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o: ../src/pattern/singelton/variant_1/Singelton.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/schoko/git/learningCpp/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o -c /home/schoko/git/learningCpp/src/pattern/singelton/variant_1/Singelton.cpp

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.i"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/schoko/git/learningCpp/src/pattern/singelton/variant_1/Singelton.cpp > CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.i

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.s"
	cd /home/schoko/git/learningCpp/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/schoko/git/learningCpp/src/pattern/singelton/variant_1/Singelton.cpp -o CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.s

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.requires:
.PHONY : src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.requires

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.provides: src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/main.dir/build.make src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.provides.build
.PHONY : src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.provides

src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.provides.build: src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: src/CMakeFiles/main.dir/main.cpp.o
main: src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o
main: src/CMakeFiles/main.dir/build.make
main: /usr/lib64/libboost_serialization.so
main: /usr/lib64/libboost_thread.so
main: /usr/lib64/libboost_date_time.so
main: /usr/lib64/libboost_filesystem.so
main: /usr/lib64/libboost_system.so
main: /usr/lib64/libboost_program_options.so
main: /usr/lib64/libboost_log.so
main: /usr/lib64/libboost_log_setup.so
main: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../main"
	cd /home/schoko/git/learningCpp/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: main
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/main.cpp.o.requires
src/CMakeFiles/main.dir/requires: src/CMakeFiles/main.dir/pattern/singelton/variant_1/Singelton.cpp.o.requires
.PHONY : src/CMakeFiles/main.dir/requires

src/CMakeFiles/main.dir/clean:
	cd /home/schoko/git/learningCpp/build/src && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	cd /home/schoko/git/learningCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/schoko/git/learningCpp /home/schoko/git/learningCpp/src /home/schoko/git/learningCpp/build /home/schoko/git/learningCpp/build/src /home/schoko/git/learningCpp/build/src/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

