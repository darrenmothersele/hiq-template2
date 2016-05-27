cmake_minimum_required(VERSION 3.5)

# Project name reused as main binary name
project(hiq)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(FREEIMAGE_FIND_REQUIRED, TRUE)
find_package(freeimage)
include_directories(SYSTEM ${FREEIMAGE_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED 3.2.8)
include_directories(${EIGEN3_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${FREEIMAGE_LIBRARIES})
