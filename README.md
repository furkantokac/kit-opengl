# Qt Creator As OpenGL Development Environment

If you want to develop OpenGL application on Qt Creator (CMake), you can use this template.


# Usage

* Install CMake : `sudo apt-get install cmake`
* Install Git : `sudo apt-get install git`
* Install GLFW, GLAD dependencies : `sudo apt-get install xorg-dev`
* Install GLEW dependencies : `sudo apt-get install build-essential libXmu-dev libXi-dev libgl-dev`
* git clone --recursive git@github.com:furkantokac/opengl-dev-qtcreator.git
* Go to Qt Creator -> Open Project -> choose the CMakeLists.txt under opengl-dev-creator directory -> "Run" the project to test
* You can work on src folder. New files/folders will be automatically added to the project after you re-run the CMake. To re-run CMake, right click the project name on Qt Creator and click "Run CMake".


# Supported Libs

* GLFW
* GLAD
* GLEW
