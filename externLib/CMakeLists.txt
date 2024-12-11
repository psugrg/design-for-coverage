##
# Library Example component configuration.
# Creates and installs a library

cmake_minimum_required(VERSION 3.16)

# The name of the library
project(externLib)

# Creates a library 
add_library(${PROJECT_NAME} src/externLib.cpp)

# Add include directories to the project
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)
