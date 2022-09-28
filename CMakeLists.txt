cmake_minimum_required(VERSION 3.23)
project(ImageProcessing)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(ImageProcessing client.cpp server.cpp MyImage.cpp MyImage.h Page.cpp Page.h PageManager.cpp PageManager.h)
target_link_libraries(ImageProcessing ${OpenCV_LIBS} )


