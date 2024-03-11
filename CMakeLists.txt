cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)


# Options

project(
        Argo-Community
        VERSION 0.0.1.0
        DESCRIPTION "Argo game engine written in C++"
        HOMEPAGE_URL "https://www.revelryplay.com/Projects/Argo/"
        LANGUAGES CXX C
)


# Graphics pipeline
# In the future multiple pipelines will be available,
# for now only enable one of these options at a time

SET(OPTS_USE_OPENGL ON) # Basic structure exists for 0.0.1; API incomplete
SET(OPTS_USE_VULKAN OFF) # Incomplete
# SET(USE_CONSOLE_ONLY OFF) # Not present at this time
# SET(USE_METAL OFF) # Not present at this time
# SET(USE_DX OFF) # Not present at this time

# End of current options


# Force one of the pipelines to be active
# This is temporary as there will also be a console only pipeline
if (NOT OPTS_USE_OPENGL AND NOT OPTS_USE_VULKAN)
    SET(USE_OPENGL ON)
endif ()

# Update version number in source file
configure_file(ArgoConfig.h.in ArgoConfig.h ESCAPE_QUOTES)

add_executable(${PROJECT_NAME}
        ArgoConfig.h.in
        src/main.cpp
        src/Runner.cpp src/Runner.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Get the latest commit hash of the working branch
# %h for short hash
# %H for full hash
find_package(Git QUIET)
if (GIT_FOUND)
    option(GET_COMMIT_HASH "Get commit hash during build" ON)
    if (NOT GET_COMMIT_HASH)
        return()
    endif ()
    execute_process(
            COMMAND ${GIT_EXECUTABLE} log -1 --format=%h
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
            OUTPUT_VARIABLE GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    message("Current Commit Hash: ${GIT_HASH}\n")
endif ()

if (OPTS_USE_OPENGL)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_OPENGL)

    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

    find_package(glad CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

    find_package(glfw3 CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

    find_package(glm CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

    find_package(imgui CONFIG REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${IMGUI_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

    find_package(robin_hood CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE robin_hood::robin_hood)

    find_package(Stb REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})
endif ()

if (OPTS_USE_VULKAN)
    target_compile_definitions(${PROJECT_NAME} PRIVATE OPTS_USE_VULKAN)
endif ()

# Add Argo Libraries
add_subdirectory(Common)
add_subdirectory(Graphics)
add_subdirectory(Utilities)

add_library(ArgoDraft STATIC IMPORTED)
set_property(TARGET ArgoDraft PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libArgoDraft.a)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ArgoCommon
        ArgoGraphics
        ArgoUtilities

        ArgoDraft
)

include(ArgoTests.cmake)
