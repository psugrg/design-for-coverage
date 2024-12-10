cmake_minimum_required(VERSION 3.16)

# Project name
project(design-for-coverage VERSION 0.1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Have cmake create a compile database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile options
add_compile_options("-Wall" "-Wextra" "-Wuninitialized")
# It's much better to add more flags especially -pedantic and -Werror
#add_compile_options("-Wall" "-Wextra" "-Wuninitialized" "-pedantic" "-Werror")

# Add new build types to support Code Coverage
message("* Adding build types...")
set(CMAKE_CXX_FLAGS_COVERAGE
    "${GCC_DEBUG_FLAGS} -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE )
set(CMAKE_C_FLAGS_COVERAGE
    "${GCC_DEBUG_FLAGS} -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE )
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE )
set(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE )
mark_as_advanced(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Debug
       CACHE STRING "Choose the type of build : None Debug Release RelWithDebInfo MinSizeRel Coverage."
       FORCE)
endif(NOT CMAKE_BUILD_TYPE)
message("* Current build type is : ${CMAKE_BUILD_TYPE}")

# Include CTest enables testing and Valgrind support for memory leak detection
include(CTest)

# Add Internal Components
add_subdirectory(objLibEx)
add_subdirectory(libEx)
add_subdirectory(doc)

# Code Coverage target
add_custom_target(coverage  
        COMMAND gcovr 
        -r ${CMAKE_CURRENT_SOURCE_DIR}
        ${coverage_files_dir}
        VERBATIM)

# Static analysis done by CPP Check
# (This will ignore the /usr/src/googletest directory)
add_custom_target(scheck ALL
        COMMAND cppcheck 
                --template=gcc 
                -i/usr/src/googletest 
                --project=compile_commands.json
        VERBATIM)

# Create application
# Add executable using OBJECTS library 
# https://cmake.org/cmake/help/v4.4/command/add_library.html#id4
add_executable(${PROJECT_NAME} $<TARGET_OBJECTS:objLibEx>)
# Link required libraries
target_link_libraries(${PROJECT_NAME} PUBLIC libEx)
# Install target configuration
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
