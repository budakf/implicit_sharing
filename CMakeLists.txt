cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER /usr/bin/gcc-10)
set(CMAKE_CXX_COMPILER /usr/bin/g++-10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++20")

project(cpp-boilerplate)
enable_testing()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(APP_DIR ${PROJECT_SOURCE_DIR}/app)
set(APP_TEST_DIR ${PROJECT_SOURCE_DIR}/app/test)
set(APP_SOURCE_DIR ${PROJECT_SOURCE_DIR}/app/src)
set(APP_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/app/include)

file(GLOB SOURCES ${APP_SOURCE_DIR}/*.cpp  ${APP_DIR}/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${APP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

# Target for Test Code
file(GLOB TEST_SOURCES ${APP_SOURCE_DIR}/*.cpp)
add_library(Test_Boilerplate STATIC ${TEST_SOURCES})
target_include_directories(Test_Boilerplate PUBLIC ${APP_INCLUDE_DIR})
target_link_libraries(Test_Boilerplate ${CONAN_LIBS})

add_subdirectory(${APP_TEST_DIR})
