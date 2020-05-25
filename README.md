# Qt Creator As OpenGL Development Environment

If you want to develop OpenGL application on Qt Creator (CMake), you can use this template.


# Usage

1. Install CMake : `sudo apt-get install cmake`
1. Install Git : `sudo apt-get install git`
1. Install GLFW, GLAD dependencies : `sudo apt-get install xorg-dev`
1. Install GLEW dependencies : `sudo apt-get install build-essential libXmu-dev libXi-dev libgl-dev`
1. `git clone --recursive git@github.com:furkantokac/kit-opengl.git`
1. Go to Qt Creator -> Open Project -> choose the CMakeLists.txt under opengl-dev-creator directory -> "Run" the project to test
1. You can work on src folder. New files/folders will be automatically added to the project after you re-run the CMake. To re-run CMake, right click the project name on Qt Creator and click "Run CMake".


# Supported Libs

* GLFW
* GLAD
* GLEW
* FreeGLUT
