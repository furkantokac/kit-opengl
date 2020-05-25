cmake_minimum_required(VERSION 2.8)
project(OpenglDevTemplate)


###
### Options
###
# Unsed previous parameters from cache for the sake of dynamism
unset(OPT_SUPPORT_GLFW CACHE)
unset(OPT_SUPPORT_GLAD CACHE)
unset(OPT_SUPPORT_GLEW CACHE)
unset(OPT_SUPPORT_FREEGLUT CACHE)

option(OPT_SUPPORT_GLFW "Set ON/OFF to enable/disable GLFW support." ON)
option(OPT_SUPPORT_GLAD "Set ON/OFF to enable/disable GLAD support." ON)
option(OPT_SUPPORT_GLEW "Set ON/OFF to enable/disable GLEW support." ON)
option(OPT_SUPPORT_FREEGLUT "Set ON/OFF to enable/disable FreeGLUT support." ON)


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
if(OPT_SUPPORT_GLFW)
    add_subdirectory(libs/glfw)
    include_directories(libs/glfw/include)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_LINK_LIBS glfw)
endif(OPT_SUPPORT_GLFW)


###
### GLAD
###
if(OPT_SUPPORT_GLAD)
    include_directories(libs/glfw/deps)
    list(APPEND PROJ_SRC
        libs/glfw/deps/glad_gl.c
        )
endif(OPT_SUPPORT_GLAD)


###
### GLEW
###
if(OPT_SUPPORT_GLEW)
    add_subdirectory(libs/glew/build/cmake)
    include_directories(libs/glew/include)
    list(APPEND PROJ_LINK_LIBS glew)
endif(OPT_SUPPORT_GLEW)


###
### FreeGLUT
###
if(OPT_SUPPORT_FREEGLUT)
    set(FREEGLUT_BUILD_DEMOS OFF)
    add_subdirectory(libs/freeglut)
    include_directories(libs/freeglut/include)
    list(APPEND PROJ_LINK_LIBS freeglut)
endif(OPT_SUPPORT_FREEGLUT)


###
### Generating the project files
###
add_executable(${PROJECT_NAME} ${PROJ_SRC})


###
### Linking to the project
###
target_link_libraries(${PROJECT_NAME} ${PROJ_LINK_LIBS})
