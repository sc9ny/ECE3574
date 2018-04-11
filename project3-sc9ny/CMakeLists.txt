cmake_minimum_required(VERSION 3.5)
project(M3 CXX)

# add any source files you create to this variable
set(SOURCE_FILES
        message_queue.hpp message_queue.cpp
        shared_double_buffer.hpp shared_double_buffer.cpp
        midiplayer.hpp midiplayer.cpp event.cpp event.hpp instrument.cpp instrument.hpp
	midi.cpp midi.hpp track.cpp track.hpp signal.cpp signal.hpp
	synthesizer.hpp synthesizer.cpp)

# try to prevent accidental in-source builds, these cause lots of problems
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Remove any files created thus far and use a different directory for the build.")
endif()
  
# require a C++11 compiler and use it for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# configure Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Multimedia Widgets Test REQUIRED)


# build midiplayer
add_executable(midiplayer main.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(midiplayer Qt5::Widgets Qt5::Multimedia pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(midiplayer Qt5::Widgets Qt5::Multimedia)
endif()

# build tests
add_executable(test_midiplayer test_midiplayer.cpp ${SOURCE_FILES})

if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_midiplayer Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_midiplayer Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()

add_executable (test_double_buffer test_double_buffer.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_double_buffer Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_double_buffer Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()
add_executable (test_message_queue test_message_queue.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_message_queue Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_message_queue Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()

add_executable (test_play test_play.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_play Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_play Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()

add_executable (test_pause test_pause.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_pause Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_pause Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()


add_executable (test_stop test_stop.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_stop Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_stop Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()

add_executable (test_resume test_resume.cpp ${SOURCE_FILES})
if(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_resume Qt5::Widgets Qt5::Multimedia Qt5::Test pthread)
else(UNIX AND NOT APPLE AND CMAKE_COMPILER_IS_GNUCXX)
  target_link_libraries(test_resume Qt5::Widgets Qt5::Multimedia Qt5::Test)
endif()
# build demo program
add_executable(noise_generator noise_generator.cpp)
target_link_libraries(noise_generator Qt5::Widgets Qt5::Multimedia)




# setup testing
enable_testing()
add_test(test_midiplayer test_midiplayer)
add_test(test_double_buffer test_double_buffer)
add_test(test_message_queue test_message_queue)
add_test(test_play test_play)
add_test(test_pause test_pause)
add_test(test_stop test_stop)
add_test(test_resume test_resume)

