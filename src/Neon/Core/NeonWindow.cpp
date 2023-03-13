#pragma once

#include <Neon/Core/NeonWindow.h>

namespace Neon {

    NeonWindow::NeonWindow(int width, int height, const string& title, NeonWindow* sharingWindow)
    {
        // Initialize GLFW
        if (!glfwInit()) {
            std::cout << "Failed to initialize GLFW" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Set GLFW window hints
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create a GLFW window
        if (sharingWindow != nullptr)
        {
            glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, sharingWindow->glfwWindow);
        }
        else
        {
            glfwWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

            if (!glfwWindow) {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                exit(EXIT_FAILURE);
            }

            MakeCurrent();

            // Load OpenGL function pointers using GLAD
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                std::cout << "Failed to initialize GLAD" << std::endl;
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
        }
    }

    NeonWindow::~NeonWindow()
    {
        // Destroy the GLFW window
        glfwDestroyWindow(glfwWindow);

        // Terminate GLFW
        glfwTerminate();
    }

    bool NeonWindow::ShouldClose()
    {
        return glfwWindowShouldClose(glfwWindow);
    }

    void NeonWindow::MakeCurrent()
    {
        glfwMakeContextCurrent(glfwWindow);
    }

    void NeonWindow::ProcessEvents()
    {
        glfwPollEvents();

        // Check if the escape key was pressed
        if (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
        }
    }

    void NeonWindow::Update(float timeDelta)
    {
    }

    void NeonWindow::SwapBuffers()
    {
        // Swap the front and back buffers
        glfwSwapBuffers(glfwWindow);
    }

}
