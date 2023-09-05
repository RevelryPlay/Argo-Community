cmake_minimum_required(VERSION 3.25)

project(ArgoUtilities
        VERSION 0.0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(${PROJECT_NAME} SHARED
        ColorConverter.cpp    ColorConverter.hpp
        )

target_link_libraries(ArgoCommon)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME} DESTINATION include)


# Testing
#find_package(PkgConfig)
#pkg_search_module(GTEST REQUIRED gtest_main)
#
#add_executable(${PROJECT_NAME}-tests)
#target_sources(${PROJECT_NAME}-tests PRIVATE ColorConverter.tests.cpp)
#target_link_libraries(${PROJECT_NAME}-tests PRIVATE ${GTEST_LDFLAGS})
#target_compile_options(${PROJECT_NAME}-tests PRIVATE ${GTEST_CFLAGS})
#
#enable_testing()
#add_test(test_color_converter ${PROJECT_NAME}-tests)
