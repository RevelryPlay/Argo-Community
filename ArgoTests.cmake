# Testing
include(CTest)

if (BUILD_TESTING)
    find_package(PkgConfig)
    find_package(GTest CONFIG REQUIRED)

    add_executable(${PROJECT_NAME}-tests)

    # NOTE: Will probably make this use a glob to build the list of files in the future
    # Additionally will make this use the graphics pipeline conditionals to filter out the unused files

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

            Graphics/OpenGL/GL2DCamera.cpp Graphics/OpenGL/GL2DCamera.hpp
            Graphics/OpenGL/GL2DEntity.cpp Graphics/OpenGL/GL2DEntity.hpp

            Graphics/OpenGL/GL2DGame.tests.cpp
            Graphics/OpenGL/GL2DGame.cpp Graphics/OpenGL/GL2DGame.hpp

            Graphics/OpenGL/GL2DLight.cpp Graphics/OpenGL/GL2DLight.hpp

            Graphics/OpenGL/GL2DScene.tests.cpp
            Graphics/OpenGL/GL2DScene.cpp Graphics/OpenGL/GL2DScene.hpp

            Graphics/OpenGL/GL2DSprite.tests.cpp
            Graphics/OpenGL/GL2DSprite.cpp Graphics/OpenGL/GL2DSprite.hpp

            Graphics/OpenGL/GL2DWindow.cpp Graphics/OpenGL/GL2DWindow.hpp

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
