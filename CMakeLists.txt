cmake_minimum_required(VERSION 3.24)

if (NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED True)


# Options

project(
        Argo-Community
        VERSION 0.0.1
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

target_link_libraries(${PROJECT_NAME} PUBLIC
        ArgoCommon
        ArgoGraphics
        ArgoUtilities
)

# Testing
include(CTest)

if (BUILD_TESTING)
    find_package(PkgConfig)
    find_package(GTest CONFIG REQUIRED)

    add_executable(${PROJECT_NAME}-tests)

    target_sources(${PROJECT_NAME}-tests PRIVATE
            Common/System/Application.tests.cpp
            Common/System/Application.cpp Common/System/Application.hpp

            Common/Types/BaseGame.tests.cpp
            Common/Types/BaseGame.cpp Common/Types/BaseGame.hpp

            Common/Types/BaseScene.tests.cpp
            Common/Types/BaseScene.cpp Common/Types/BaseScene.hpp

            Common/Types/CommonColor.tests.cpp
            Common/Types/CommonColor.cpp Common/Types/CommonColor.hpp
            Common/Types/Vec4.hpp

            Graphics/OpenGL/GLGame.tests.cpp
            Graphics/OpenGL/GLCamera.cpp Graphics/OpenGL/GLCamera.hpp
            Graphics/OpenGL/GLGame.cpp Graphics/OpenGL/GLGame.hpp
            Graphics/OpenGL/GLLight.cpp Graphics/OpenGL/GLLight.hpp

            Graphics/OpenGL/GLScene.tests.cpp
            Graphics/OpenGL/GLScene.cpp Graphics/OpenGL/GLScene.hpp
            Graphics/OpenGL/GLWindow.cpp Graphics/OpenGL/GLWindow.hpp
            Common/Types/BaseWindow.cpp Common/Types/BaseWindow.hpp
            Common/System/Window.hpp

            Utilities/ColorConverter.cpp Utilities/ColorConverter.hpp
            Utilities/ColorConverter.tests.cpp
    )

    target_include_directories(${PROJECT_NAME}-tests PUBLIC ${PROJECT_BINARY_DIR})

    target_compile_definitions(${PROJECT_NAME}-tests PRIVATE OPTS_USE_OPENGL)

    find_package(OpenGL REQUIRED)
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE OpenGL::GL)

    find_package(glad CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glad::glad)

    find_package(glfw3 CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glfw)

    find_package(glm CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME}-tests PRIVATE glm::glm)

    enable_testing()

    target_link_libraries(${PROJECT_NAME}-tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    target_compile_options(${PROJECT_NAME}-tests PRIVATE ${GTEST_CFLAGS})

    include(GoogleTest)

    gtest_discover_tests(${PROJECT_NAME}-tests)
endif ()
