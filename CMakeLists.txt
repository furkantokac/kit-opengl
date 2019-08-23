cmake_minimum_required(VERSION 2.8)
project(OpenglTutor1)


# Compiler definitions
add_definitions(-fPIC)


# External library paths
add_subdirectory(libs/glfw)
include_directories(
        libs/glfw/include
        libs/glfw/deps
)
set(GLAD_GL libs/glfw/deps/glad/gl.h libs/glfw/deps/glad_gl.c)


# Generating the project files
add_executable(${PROJECT_NAME} main.cpp ${GLAD_GL})


# Linking to the project
target_link_libraries(${PROJECT_NAME} glfw)
