cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)

project(
        Argo-Community
        VERSION 0.0.1
        DESCRIPTION "Argo game engine written in C++"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)

# Update version number in source file
configure_file(ArgoConfig.h.in ArgoConfig.h ESCAPE_QUOTES)

add_executable(${PROJECT_NAME}
        ArgoConfig.h.in
        src/main.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Get the latest commit hash of the working branch
# %h for short hash
# %H for full hash
find_package(Git QUIET)
if(GIT_FOUND)
    option(GET_COMMIT_HASH "Get commit hash during build" ON)
    if(NOT GET_COMMIT_HASH)
        return()
    endif()
    execute_process(
            COMMAND ${GIT_EXECUTABLE} log -1 --format=%h
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message("Current Commit Hash: ${GIT_HASH}\n")
endif()

# Add Argo Libraries
add_subdirectory(Common)
add_subdirectory(Networking)
add_subdirectory(Utilities)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ArgoCommon
        ArgoNetworking
        ArgoUtilities
)


# Testing
include(CTest)

if (BUILD_TESTING)
    find_package(PkgConfig)
    find_package(GTest CONFIG REQUIRED)

    add_executable(${PROJECT_NAME}-tests)
    target_sources(${PROJECT_NAME}-tests PRIVATE
            Utilities/ColorConverter.cpp    Utilities/ColorConverter.hpp
            Utilities/ColorConverter.tests.cpp
    )

    enable_testing()

    target_link_libraries(${PROJECT_NAME}-tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    target_compile_options(${PROJECT_NAME}-tests PRIVATE ${GTEST_CFLAGS})

    add_test(test_color_converter ${PROJECT_NAME}-tests)
endif ()
