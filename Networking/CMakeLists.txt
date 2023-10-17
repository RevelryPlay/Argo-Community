cmake_minimum_required(VERSION 3.25)

project(ArgoNetworking
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} SHARED
        Networking.cpp Networking.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
