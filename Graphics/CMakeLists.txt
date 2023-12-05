cmake_minimum_required(VERSION 3.25)

project(ArgoGraphics
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} STATIC
        OpenGL/GLCamera.cpp OpenGL/GLCamera.hpp
        OpenGL/GLEntity.cpp OpenGL/GLEntity.hpp
        OpenGL/GLGame.cpp OpenGL/GLGame.hpp
        OpenGL/GLScene.cpp OpenGL/GLScene.hpp
        OpenGL/GLSprite.cpp OpenGL/GLSprite.hpp
        OpenGL/GLWindow.cpp OpenGL/GLWindow.hpp
)

target_link_libraries(ArgoCommon)

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

# Install ArgoGraphics
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
