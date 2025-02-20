cmake_minimum_required(VERSION 3.12)
project(GameOfLife VERSION 0.1.0 LANGUAGES C CXX)

# Find the Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64/bin/")

#gtest
set (gtest_disable_pthreads on)
add_subdirectory (gmock/turtle/googletest-main)
config_compiler_and_linker()

# Find the required Qt components
find_package(Qt6 COMPONENTS Widgets REQUIRED)

#Enable MOC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add the executable
add_executable(GameOfLife
                main.cpp
                GameOfLifeModel.cpp
                GridWidgetView.cpp
                GameOfLifeController.cpp
)

#gtest
add_executable(GameOfLifeTests test_game_of_life.cpp GameOfLifeModel.cpp)
target_link_libraries (GameOfLifeTests gtest GTest::gtest_main gmock)
# Add tests to ctest
add_test(NAME GameOfLifeTests COMMAND GameOfLifeTests)
 
include(GoogleTest)
gtest_discover_tests(GameOfLifeTests
    DISCOVERY_MODE PRE_TEST
    TEST_PREFIX GameOfLife.
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)
 
# Link the Qt libraries
target_link_libraries(GameOfLife Qt6::Widgets)

include(CTest)
enable_testing()