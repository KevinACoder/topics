# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/code/c/all_topics/v2_topics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/code/c/all_topics/v2_topics

# Include any dependencies generated for this target.
include CMakeFiles/topics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/topics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/topics.dir/flags.make

CMakeFiles/topics.dir/src/main.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/topics.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/main.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/main.cpp

CMakeFiles/topics.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/main.cpp > CMakeFiles/topics.dir/src/main.cpp.i

CMakeFiles/topics.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/main.cpp -o CMakeFiles/topics.dir/src/main.cpp.s

CMakeFiles/topics.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/main.cpp.o.requires

CMakeFiles/topics.dir/src/main.cpp.o.provides: CMakeFiles/topics.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/main.cpp.o.provides

CMakeFiles/topics.dir/src/main.cpp.o.provides.build: CMakeFiles/topics.dir/src/main.cpp.o


CMakeFiles/topics.dir/src/date_time_t.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/date_time_t.cpp.o: src/date_time_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/topics.dir/src/date_time_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/date_time_t.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/date_time_t.cpp

CMakeFiles/topics.dir/src/date_time_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/date_time_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/date_time_t.cpp > CMakeFiles/topics.dir/src/date_time_t.cpp.i

CMakeFiles/topics.dir/src/date_time_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/date_time_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/date_time_t.cpp -o CMakeFiles/topics.dir/src/date_time_t.cpp.s

CMakeFiles/topics.dir/src/date_time_t.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/date_time_t.cpp.o.requires

CMakeFiles/topics.dir/src/date_time_t.cpp.o.provides: CMakeFiles/topics.dir/src/date_time_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/date_time_t.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/date_time_t.cpp.o.provides

CMakeFiles/topics.dir/src/date_time_t.cpp.o.provides.build: CMakeFiles/topics.dir/src/date_time_t.cpp.o


CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o: src/smart_ptr_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/smart_ptr_t.cpp

CMakeFiles/topics.dir/src/smart_ptr_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/smart_ptr_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/smart_ptr_t.cpp > CMakeFiles/topics.dir/src/smart_ptr_t.cpp.i

CMakeFiles/topics.dir/src/smart_ptr_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/smart_ptr_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/smart_ptr_t.cpp -o CMakeFiles/topics.dir/src/smart_ptr_t.cpp.s

CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.requires

CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.provides: CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.provides

CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.provides.build: CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o


CMakeFiles/topics.dir/src/utility_t.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/utility_t.cpp.o: src/utility_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/topics.dir/src/utility_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/utility_t.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/utility_t.cpp

CMakeFiles/topics.dir/src/utility_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/utility_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/utility_t.cpp > CMakeFiles/topics.dir/src/utility_t.cpp.i

CMakeFiles/topics.dir/src/utility_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/utility_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/utility_t.cpp -o CMakeFiles/topics.dir/src/utility_t.cpp.s

CMakeFiles/topics.dir/src/utility_t.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/utility_t.cpp.o.requires

CMakeFiles/topics.dir/src/utility_t.cpp.o.provides: CMakeFiles/topics.dir/src/utility_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/utility_t.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/utility_t.cpp.o.provides

CMakeFiles/topics.dir/src/utility_t.cpp.o.provides.build: CMakeFiles/topics.dir/src/utility_t.cpp.o


CMakeFiles/topics.dir/src/system_t.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/system_t.cpp.o: src/system_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/topics.dir/src/system_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/system_t.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/system_t.cpp

CMakeFiles/topics.dir/src/system_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/system_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/system_t.cpp > CMakeFiles/topics.dir/src/system_t.cpp.i

CMakeFiles/topics.dir/src/system_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/system_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/system_t.cpp -o CMakeFiles/topics.dir/src/system_t.cpp.s

CMakeFiles/topics.dir/src/system_t.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/system_t.cpp.o.requires

CMakeFiles/topics.dir/src/system_t.cpp.o.provides: CMakeFiles/topics.dir/src/system_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/system_t.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/system_t.cpp.o.provides

CMakeFiles/topics.dir/src/system_t.cpp.o.provides.build: CMakeFiles/topics.dir/src/system_t.cpp.o


CMakeFiles/topics.dir/src/string_t.cpp.o: CMakeFiles/topics.dir/flags.make
CMakeFiles/topics.dir/src/string_t.cpp.o: src/string_t.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/topics.dir/src/string_t.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/topics.dir/src/string_t.cpp.o -c /home/pi/code/c/all_topics/v2_topics/src/string_t.cpp

CMakeFiles/topics.dir/src/string_t.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/topics.dir/src/string_t.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/code/c/all_topics/v2_topics/src/string_t.cpp > CMakeFiles/topics.dir/src/string_t.cpp.i

CMakeFiles/topics.dir/src/string_t.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/topics.dir/src/string_t.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/code/c/all_topics/v2_topics/src/string_t.cpp -o CMakeFiles/topics.dir/src/string_t.cpp.s

CMakeFiles/topics.dir/src/string_t.cpp.o.requires:

.PHONY : CMakeFiles/topics.dir/src/string_t.cpp.o.requires

CMakeFiles/topics.dir/src/string_t.cpp.o.provides: CMakeFiles/topics.dir/src/string_t.cpp.o.requires
	$(MAKE) -f CMakeFiles/topics.dir/build.make CMakeFiles/topics.dir/src/string_t.cpp.o.provides.build
.PHONY : CMakeFiles/topics.dir/src/string_t.cpp.o.provides

CMakeFiles/topics.dir/src/string_t.cpp.o.provides.build: CMakeFiles/topics.dir/src/string_t.cpp.o


# Object files for target topics
topics_OBJECTS = \
"CMakeFiles/topics.dir/src/main.cpp.o" \
"CMakeFiles/topics.dir/src/date_time_t.cpp.o" \
"CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o" \
"CMakeFiles/topics.dir/src/utility_t.cpp.o" \
"CMakeFiles/topics.dir/src/system_t.cpp.o" \
"CMakeFiles/topics.dir/src/string_t.cpp.o"

# External object files for target topics
topics_EXTERNAL_OBJECTS =

topics: CMakeFiles/topics.dir/src/main.cpp.o
topics: CMakeFiles/topics.dir/src/date_time_t.cpp.o
topics: CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o
topics: CMakeFiles/topics.dir/src/utility_t.cpp.o
topics: CMakeFiles/topics.dir/src/system_t.cpp.o
topics: CMakeFiles/topics.dir/src/string_t.cpp.o
topics: CMakeFiles/topics.dir/build.make
topics: /usr/local/lib/libboost_regex.so
topics: /usr/local/lib/libboost_system.so
topics: CMakeFiles/topics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/code/c/all_topics/v2_topics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable topics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/topics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/topics.dir/build: topics

.PHONY : CMakeFiles/topics.dir/build

CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/main.cpp.o.requires
CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/date_time_t.cpp.o.requires
CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/smart_ptr_t.cpp.o.requires
CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/utility_t.cpp.o.requires
CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/system_t.cpp.o.requires
CMakeFiles/topics.dir/requires: CMakeFiles/topics.dir/src/string_t.cpp.o.requires

.PHONY : CMakeFiles/topics.dir/requires

CMakeFiles/topics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/topics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/topics.dir/clean

CMakeFiles/topics.dir/depend:
	cd /home/pi/code/c/all_topics/v2_topics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/code/c/all_topics/v2_topics /home/pi/code/c/all_topics/v2_topics /home/pi/code/c/all_topics/v2_topics /home/pi/code/c/all_topics/v2_topics /home/pi/code/c/all_topics/v2_topics/CMakeFiles/topics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/topics.dir/depend

