cmake_minimum_required(VERSION 2.8)
project(OpenglDevTemplate)


###
### Options
###
# Unsed previous parameters from cache for the sake of dynamism
unset(KITGL_SUPPORT_GLFW CACHE)
unset(KITGL_SUPPORT_GLAD CACHE)
unset(KITGL_SUPPORT_GLEW CACHE)
unset(KITGL_SUPPORT_FREEGLUT CACHE)

# Enable desired libs
option(KITGL_SUPPORT_GLFW "Set ON/OFF to enable/disable GLFW support." ON)
option(KITGL_SUPPORT_GLAD "Set ON/OFF to enable/disable GLAD support." ON)
option(KITGL_SUPPORT_GLEW "Set ON/OFF to enable/disable GLEW support." ON)
option(KITGL_SUPPORT_FREEGLUT "Set ON/OFF to enable/disable FreeGLUT support." ON)


###
### Initialization
###
# Project parameters
set(PROJ_LINK_LIBS)
set(PROJ_SRC)

# Add all files/folders under src folder automatically to the project
file(GLOB_RECURSE PROJ_SRC src/*.h src/*.cpp)


###
### Compiler settings
###
add_definitions(
    -fPIC
    )


###
### GLFW
###
if(KITGL_SUPPORT_GLFW)
    # Disable internal builds
    unset(GLFW_BUILD_EXAMPLES CACHE)
    unset(GLFW_BUILD_TESTS CACHE)
    unset(GLFW_BUILD_DOCS CACHE)
    option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
    option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
    option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)

    add_subdirectory(libs/glfw)
    include_directories(libs/glfw/include)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_LINK_LIBS glfw)
endif(KITGL_SUPPORT_GLFW)


###
### GLAD
###
if(KITGL_SUPPORT_GLAD)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_SRC
        libs/glfw/deps/glad_gl.c
        )
endif(KITGL_SUPPORT_GLAD)


###
### GLEW
###
if(KITGL_SUPPORT_GLEW)
    # Disable internal builds
    unset(BUILD_UTILS CACHE)
    option(BUILD_UTILS "utilities" OFF)

    add_subdirectory(libs/glew/build/cmake)
    include_directories(libs/glew/include)
    list(APPEND PROJ_LINK_LIBS glew)
endif(KITGL_SUPPORT_GLEW)


###
### FreeGLUT
###
if(KITGL_SUPPORT_FREEGLUT)
    # Disable internal builds
    unset(FREEGLUT_BUILD_DEMOS CACHE)
    option(FREEGLUT_BUILD_DEMOS "Build FreeGLUT demos." OFF)

    add_subdirectory(libs/freeglut)
    include_directories(libs/freeglut/include)
    list(APPEND PROJ_LINK_LIBS freeglut)
endif(KITGL_SUPPORT_FREEGLUT)


###
### Generating the project files
###
add_executable(${PROJECT_NAME} ${PROJ_SRC})


###
### Linking to the project
###
target_link_libraries(${PROJECT_NAME} ${PROJ_LINK_LIBS})
