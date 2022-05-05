cmake_minimum_required(VERSION 3.16)

project(juce_litehtml_test)

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(JUCE)
add_subdirectory(juce_litehtml)

add_subdirectory(browser)
