cmake_minimum_required(VERSION 3.23)
project(ImageProcessing)

find_package(OpenCV REQUIRED)
find_package(Boost 1.71.0 REQUIRED system)

set(CMAKE_CXX_STANDARD 14)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(ImageProcessing client.cpp Filters.cpp Filters.h)
target_link_libraries(ImageProcessing ${OpenCV_LIBS} )


