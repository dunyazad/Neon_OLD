#include <Neon/Neon.h>
#include <Neon/NeonApp.h>

#include <iostream>
#include "window.h"
#include "shader.h"

int main() {
    unsigned int VBO, VAO;
    Shader* shader = nullptr;

    Neon::NeonApp app;
    app.CreateNeonWindow(1024, 768, "Neon");

    app.OnInitialize([&]() {

    // Define the vertices of the triangle
    float vertices[] = {
         0.0f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    // Create the vertex buffer object and vertex array object
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    // Bind the vertex array object and vertex buffer object
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Copy the vertices data into the vertex buffer object
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Specify the vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Create the shader program
    shader = new Shader("D:/Workspace/Neon/res/shader/vertexShader.glsl", "D:/Workspace/Neon/res/shader/fragmentShader.glsl");
        });

    app.OnFrame([&]() {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle
    shader->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
        });

    app.OnTerminate([&]() {
        delete shader;

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
        });

    app.Run();

    return 0;
}
