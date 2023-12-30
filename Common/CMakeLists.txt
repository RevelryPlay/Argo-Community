cmake_minimum_required(VERSION 3.25)

project(ArgoCommon
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} STATIC
        System/Application.cpp System/Application.hpp
        System/Camera.hpp
        System/Entity.hpp
        System/Game.hpp
        System/Light.hpp
        System/Scene.hpp
        System/Sprite.hpp
        System/Window.hpp

        Types/CommonColor.cpp Types/CommonColor.hpp
        Types/BaseCamera.cpp Types/BaseCamera.hpp
        Types/BaseEntity.cpp Types/BaseEntity.hpp
        Types/BaseGame.cpp Types/BaseGame.hpp
        Types/BaseLight.cpp Types/BaseLight.hpp
        Types/BaseScene.cpp Types/BaseScene.hpp
        Types/BaseSprite.cpp Types/BaseSprite.hpp
        Types/BaseWindow.cpp Types/BaseWindow.hpp
        Types/Vec4.hpp
        Types/Vec3.hpp

        Constants.hpp
)

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

# Install ArgoCommon

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
