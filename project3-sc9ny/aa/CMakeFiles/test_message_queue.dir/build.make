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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seungleechoi/desktop/ECE3574/project3-sc9ny

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa

# Include any dependencies generated for this target.
include CMakeFiles/test_message_queue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_message_queue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_message_queue.dir/flags.make

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o: ../test_message_queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/test_message_queue.cpp

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/test_message_queue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/test_message_queue.cpp > CMakeFiles/test_message_queue.dir/test_message_queue.cpp.i

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/test_message_queue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/test_message_queue.cpp -o CMakeFiles/test_message_queue.dir/test_message_queue.cpp.s

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.requires

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.provides: CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.provides

CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o


CMakeFiles/test_message_queue.dir/message_queue.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/message_queue.cpp.o: ../message_queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_message_queue.dir/message_queue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/message_queue.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/message_queue.cpp

CMakeFiles/test_message_queue.dir/message_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/message_queue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/message_queue.cpp > CMakeFiles/test_message_queue.dir/message_queue.cpp.i

CMakeFiles/test_message_queue.dir/message_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/message_queue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/message_queue.cpp -o CMakeFiles/test_message_queue.dir/message_queue.cpp.s

CMakeFiles/test_message_queue.dir/message_queue.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/message_queue.cpp.o.requires

CMakeFiles/test_message_queue.dir/message_queue.cpp.o.provides: CMakeFiles/test_message_queue.dir/message_queue.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/message_queue.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/message_queue.cpp.o.provides

CMakeFiles/test_message_queue.dir/message_queue.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/message_queue.cpp.o


CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o: ../shared_double_buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/shared_double_buffer.cpp

CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/shared_double_buffer.cpp > CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.i

CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/shared_double_buffer.cpp -o CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.s

CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.requires

CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.provides: CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.provides

CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o


CMakeFiles/test_message_queue.dir/midiplayer.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/midiplayer.cpp.o: ../midiplayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_message_queue.dir/midiplayer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/midiplayer.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midiplayer.cpp

CMakeFiles/test_message_queue.dir/midiplayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/midiplayer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midiplayer.cpp > CMakeFiles/test_message_queue.dir/midiplayer.cpp.i

CMakeFiles/test_message_queue.dir/midiplayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/midiplayer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midiplayer.cpp -o CMakeFiles/test_message_queue.dir/midiplayer.cpp.s

CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.requires

CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.provides: CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.provides

CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/midiplayer.cpp.o


CMakeFiles/test_message_queue.dir/event.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/event.cpp.o: ../event.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test_message_queue.dir/event.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/event.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/event.cpp

CMakeFiles/test_message_queue.dir/event.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/event.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/event.cpp > CMakeFiles/test_message_queue.dir/event.cpp.i

CMakeFiles/test_message_queue.dir/event.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/event.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/event.cpp -o CMakeFiles/test_message_queue.dir/event.cpp.s

CMakeFiles/test_message_queue.dir/event.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/event.cpp.o.requires

CMakeFiles/test_message_queue.dir/event.cpp.o.provides: CMakeFiles/test_message_queue.dir/event.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/event.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/event.cpp.o.provides

CMakeFiles/test_message_queue.dir/event.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/event.cpp.o


CMakeFiles/test_message_queue.dir/instrument.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/instrument.cpp.o: ../instrument.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test_message_queue.dir/instrument.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/instrument.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/instrument.cpp

CMakeFiles/test_message_queue.dir/instrument.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/instrument.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/instrument.cpp > CMakeFiles/test_message_queue.dir/instrument.cpp.i

CMakeFiles/test_message_queue.dir/instrument.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/instrument.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/instrument.cpp -o CMakeFiles/test_message_queue.dir/instrument.cpp.s

CMakeFiles/test_message_queue.dir/instrument.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/instrument.cpp.o.requires

CMakeFiles/test_message_queue.dir/instrument.cpp.o.provides: CMakeFiles/test_message_queue.dir/instrument.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/instrument.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/instrument.cpp.o.provides

CMakeFiles/test_message_queue.dir/instrument.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/instrument.cpp.o


CMakeFiles/test_message_queue.dir/midi.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/midi.cpp.o: ../midi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/test_message_queue.dir/midi.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/midi.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midi.cpp

CMakeFiles/test_message_queue.dir/midi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/midi.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midi.cpp > CMakeFiles/test_message_queue.dir/midi.cpp.i

CMakeFiles/test_message_queue.dir/midi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/midi.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/midi.cpp -o CMakeFiles/test_message_queue.dir/midi.cpp.s

CMakeFiles/test_message_queue.dir/midi.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/midi.cpp.o.requires

CMakeFiles/test_message_queue.dir/midi.cpp.o.provides: CMakeFiles/test_message_queue.dir/midi.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/midi.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/midi.cpp.o.provides

CMakeFiles/test_message_queue.dir/midi.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/midi.cpp.o


CMakeFiles/test_message_queue.dir/track.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/track.cpp.o: ../track.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/test_message_queue.dir/track.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/track.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/track.cpp

CMakeFiles/test_message_queue.dir/track.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/track.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/track.cpp > CMakeFiles/test_message_queue.dir/track.cpp.i

CMakeFiles/test_message_queue.dir/track.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/track.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/track.cpp -o CMakeFiles/test_message_queue.dir/track.cpp.s

CMakeFiles/test_message_queue.dir/track.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/track.cpp.o.requires

CMakeFiles/test_message_queue.dir/track.cpp.o.provides: CMakeFiles/test_message_queue.dir/track.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/track.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/track.cpp.o.provides

CMakeFiles/test_message_queue.dir/track.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/track.cpp.o


CMakeFiles/test_message_queue.dir/signal.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/signal.cpp.o: ../signal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/test_message_queue.dir/signal.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/signal.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/signal.cpp

CMakeFiles/test_message_queue.dir/signal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/signal.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/signal.cpp > CMakeFiles/test_message_queue.dir/signal.cpp.i

CMakeFiles/test_message_queue.dir/signal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/signal.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/signal.cpp -o CMakeFiles/test_message_queue.dir/signal.cpp.s

CMakeFiles/test_message_queue.dir/signal.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/signal.cpp.o.requires

CMakeFiles/test_message_queue.dir/signal.cpp.o.provides: CMakeFiles/test_message_queue.dir/signal.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/signal.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/signal.cpp.o.provides

CMakeFiles/test_message_queue.dir/signal.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/signal.cpp.o


CMakeFiles/test_message_queue.dir/synthesizer.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/synthesizer.cpp.o: ../synthesizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/test_message_queue.dir/synthesizer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/synthesizer.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/synthesizer.cpp

CMakeFiles/test_message_queue.dir/synthesizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/synthesizer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/synthesizer.cpp > CMakeFiles/test_message_queue.dir/synthesizer.cpp.i

CMakeFiles/test_message_queue.dir/synthesizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/synthesizer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/synthesizer.cpp -o CMakeFiles/test_message_queue.dir/synthesizer.cpp.s

CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.requires

CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.provides: CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.provides

CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/synthesizer.cpp.o


CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o: CMakeFiles/test_message_queue.dir/flags.make
CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o: test_message_queue_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o -c /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/test_message_queue_automoc.cpp

CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/test_message_queue_automoc.cpp > CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.i

CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/test_message_queue_automoc.cpp -o CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.s

CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.requires:

.PHONY : CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.requires

CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.provides: CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_message_queue.dir/build.make CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.provides

CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.provides.build: CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o


# Object files for target test_message_queue
test_message_queue_OBJECTS = \
"CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o" \
"CMakeFiles/test_message_queue.dir/message_queue.cpp.o" \
"CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o" \
"CMakeFiles/test_message_queue.dir/midiplayer.cpp.o" \
"CMakeFiles/test_message_queue.dir/event.cpp.o" \
"CMakeFiles/test_message_queue.dir/instrument.cpp.o" \
"CMakeFiles/test_message_queue.dir/midi.cpp.o" \
"CMakeFiles/test_message_queue.dir/track.cpp.o" \
"CMakeFiles/test_message_queue.dir/signal.cpp.o" \
"CMakeFiles/test_message_queue.dir/synthesizer.cpp.o" \
"CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o"

# External object files for target test_message_queue
test_message_queue_EXTERNAL_OBJECTS =

test_message_queue: CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/message_queue.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/midiplayer.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/event.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/instrument.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/midi.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/track.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/signal.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/synthesizer.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o
test_message_queue: CMakeFiles/test_message_queue.dir/build.make
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtWidgets.framework/QtWidgets
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtMultimedia.framework/QtMultimedia
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtTest.framework/QtTest
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtGui.framework/QtGui
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtNetwork.framework/QtNetwork
test_message_queue: /Users/seungleechoi/qt/5.9.2/clang_64/lib/QtCore.framework/QtCore
test_message_queue: CMakeFiles/test_message_queue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable test_message_queue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_message_queue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_message_queue.dir/build: test_message_queue

.PHONY : CMakeFiles/test_message_queue.dir/build

CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/test_message_queue.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/message_queue.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/shared_double_buffer.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/midiplayer.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/event.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/instrument.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/midi.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/track.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/signal.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/synthesizer.cpp.o.requires
CMakeFiles/test_message_queue.dir/requires: CMakeFiles/test_message_queue.dir/test_message_queue_automoc.cpp.o.requires

.PHONY : CMakeFiles/test_message_queue.dir/requires

CMakeFiles/test_message_queue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_message_queue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_message_queue.dir/clean

CMakeFiles/test_message_queue.dir/depend:
	cd /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seungleechoi/desktop/ECE3574/project3-sc9ny /Users/seungleechoi/desktop/ECE3574/project3-sc9ny /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa /Users/seungleechoi/desktop/ECE3574/project3-sc9ny/aa/CMakeFiles/test_message_queue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_message_queue.dir/depend

