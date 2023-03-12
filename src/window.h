#pragma once

#include <Neon/NeonCommon.h>

class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool shouldClose();
    void processEvents();
    void swapBuffers();

private:
    GLFWwindow* m_Window;
};

Window::Window(int width, int height, const char* title) {
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
    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_Window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Make the window's context current
    glfwMakeContextCurrent(m_Window);

    // Load OpenGL function pointers using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

Window::~Window() {
    // Destroy the GLFW window
    glfwDestroyWindow(m_Window);

    // Terminate GLFW
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(m_Window);
}

void Window::processEvents() {
    glfwPollEvents();

    // Check if the escape key was pressed
    if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
    }
}

void Window::swapBuffers() {
    // Swap the front and back buffers
    glfwSwapBuffers(m_Window);
}