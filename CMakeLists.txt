cmake_minimum_required(VERSION 3.23)
project(ImageProcessing)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_subdirectory(src)
add_subdirectory(Google_Tests_run)
add_subdirectory(lib/googletest)
add_executable(ImageProcessing src/client.cpp src/server.cpp src/MyImage.cpp src/MyImage.h src/Page.cpp src/Page.h src/PageManager.cpp src/PageManager.h src/Filters.cpp src/Filters.h)
target_link_libraries(ImageProcessing ${OpenCV_LIBS} )



