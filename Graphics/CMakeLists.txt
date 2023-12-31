cmake_minimum_required(VERSION 3.25)

project(ArgoGraphics
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

if (OPTS_USE_OPENGL)
    add_library(${PROJECT_NAME} STATIC
            OpenGL/GL2DCamera.cpp OpenGL/GL2DCamera.hpp
            OpenGL/GL2DEntity.cpp OpenGL/GL2DEntity.hpp
            OpenGL/GL2DGame.cpp OpenGL/GL2DGame.hpp
            OpenGL/GL2DLight.cpp OpenGL/GL2DLight.hpp
            OpenGL/GL2DScene.cpp OpenGL/GL2DScene.hpp
            OpenGL/GL2DShader.cpp OpenGL/GL2DShader.hpp
            OpenGL/GL2DSprite.cpp OpenGL/GL2DSprite.hpp
            OpenGL/GL2DWindow.cpp OpenGL/GL2DWindow.hpp
    )
endif ()

if (OPTS_USE_VULKAN)
    add_library(${PROJECT_NAME} STATIC
            Vulkan/VKCamera.cpp Vulkan/VKCamera.hpp
            Vulkan/VKEntity.cpp Vulkan/VKEntity.hpp
            Vulkan/VKGame.cpp Vulkan/VKGame.hpp
            Vulkan/VKLight.cpp Vulkan/VKLight.hpp
            Vulkan/VKScene.cpp Vulkan/VKScene.hpp
            Vulkan/VKSprite.cpp Vulkan/VKSprite.hpp
            Vulkan/VKWindow.cpp Vulkan/VKWindow.hpp
            Vulkan/VKShader.cpp Vulkan/VKShader.hpp
    )
endif ()

target_link_libraries(ArgoCommon)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Common Libraries

# This is duplicated from the Argo main project. In the future these will be optional and also
# pruned to only the libraries actually used in this module
if (OPTS_USE_OPENGL)
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

# Install ArgoGraphics
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
