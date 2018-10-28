# set project information
project(topics)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

# the version number
set (TOPICS_VERSION_MAJOR 0)
set (TOPICS_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/topics_config.h.in"
    "${PROJECT_BINARY_DIR}/topics_config.h"
)

# add the binary tree to the search path for include files
# so that we will find topics_config.h
include_directories("${PROJECT_BINARY_DIR}")


# use customerize boost library
set(BOOST_ROOT /home/pi/boost/boost_1_60_0)
find_package(Boost COMPONENTS regex system REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")

    add_executable(topics 
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/date_time_t.cpp
        ${PROJECT_SOURCE_DIR}/src/smart_ptr_t.cpp
        ${PROJECT_SOURCE_DIR}/src/utility_t.cpp)
    target_link_libraries (topics ${Boost_LIBRARIES})
endif()