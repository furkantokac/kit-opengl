#include <iostream>
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main()
{
        GLFWwindow* window;

        if (!glfwInit()) return -1;

        window = glfwCreateWindow(800, 480, "ftDev's Window", nullptr, nullptr);
        if (!window)
        {
                glfwTerminate();
                return -1;
        }

        glfwSetKeyCallback(window, key_callback);
        glfwMakeContextCurrent(window);
        gladLoadGL(glfwGetProcAddress);

        int flickerCounter = 0;
        while (!glfwWindowShouldClose(window))
        {
                glfwPollEvents();

                if (flickerCounter < 15)        glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
                else if (flickerCounter < 30)   glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
                else                            flickerCounter = 0;
                glClear(GL_COLOR_BUFFER_BIT);

                glfwSwapBuffers(window);
                flickerCounter++;
        }

        // Clean up
        glfwTerminate();
        return 0;
}

