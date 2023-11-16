cmake_minimum_required(VERSION 3.25)

project(ArgoCommon
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} STATIC
        Graphics/OpenGL/GLCamera.cpp Graphics/OpenGL/GLCamera.hpp
        Graphics/OpenGL/GLEntity.cpp Graphics/OpenGL/GLEntity.hpp
        Graphics/OpenGL/GLScene.cpp Graphics/OpenGL/GLScene.hpp
        Graphics/OpenGL/GLWindow.cpp Graphics/OpenGL/GLWindow.hpp

        System/BaseGame.cpp System/BaseGame.hpp
        System/GLGame.cpp System/GLGame.hpp
        System/Game.cpp System/Game.hpp
        System/Application.cpp System/Application.hpp

        Types/CommonColor.cpp Types/CommonColor.hpp
        Types/Vec4.hpp

        Constants.hpp
        Graphics/OpenGL/GLSprite.cpp
        Graphics/OpenGL/GLSprite.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Common Libraries

# This is duplicated from the Argo main project. In the future these will be optional and also
# pruned to only the libraries actually used in this module
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

# Install ArgoCommon

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
