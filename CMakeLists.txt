cmake_minimum_required(VERSION 2.8)
project(OpenglDevTemplate)

set(PROJ_SRC main.cpp)
set(PROJ_LINK_LIBS)

###
### Compiler settings
###
add_definitions(
        -fPIC
)

###
### GLFW
###
add_subdirectory(libs/glfw)
include_directories(libs/glfw/include)
include_directories(libs/glfw/deps)
list(APPEND PROJ_LINK_LIBS glfw)

###
### GLAD
###
list(APPEND PROJ_SRC
        libs/glfw/deps/glad/gl.h
        libs/glfw/deps/glad_gl.c
)

###
### GLEW
###
add_subdirectory(libs/glew/build/cmake)
include_directories(libs/glew/include)
list(APPEND PROJ_LINK_LIBS glew)

###
### Generating the project files
###
add_executable(${PROJECT_NAME} ${PROJ_SRC})

###
### Linking to the project
###
target_link_libraries(${PROJECT_NAME} ${PROJ_LINK_LIBS})
