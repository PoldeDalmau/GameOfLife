cmake_minimum_required(VERSION 3.12)
project(GameOfLife VERSION 0.1.0 LANGUAGES C CXX)

# Find the Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/bin/")

# Find the required Qt components
find_package(Qt6 COMPONENTS Widgets REQUIRED)

#Enable MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add the executable
add_executable(GameOfLife main.cpp)

# Link the Qt libraries
target_link_libraries(GameOfLife Qt6::Widgets)

include(CTest)
enable_testing()