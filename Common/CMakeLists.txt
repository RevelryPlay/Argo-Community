cmake_minimum_required(VERSION 3.25)

project(ArgoCommon
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} SHARED
        System/FileSystem/CSVHandler.cpp       System/FileSystem/CSVHandler.hpp
        System/FileSystem/FileHandler.cpp      System/FileSystem/FileHandler.hpp
        System/FileSystem/IniHandler.cpp       System/FileSystem/IniHandler.hpp
        System/FileSystem/JsonHandler.cpp      System/FileSystem/JsonHandler.hpp
        System/FileSystem/YamlHandler.cpp      System/FileSystem/YamlHandler.hpp
        System/FileSystem/XmlHandler.cpp       System/FileSystem/XmlHandler.hpp

        System/ThreadPool.cpp       System/ThreadPool.hpp

        Types/CommonColor.cpp                  Types/CommonColor.hpp
        Types/Vec4.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)
