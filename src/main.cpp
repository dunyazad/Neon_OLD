#include <Neon/Neon.h>
#include <Neon/NeonApp.h>
#include <Neon/GraphicsAPI/Shader/NeonShader.h>

#include <iostream>
#include "shader.h"

int main() {
    unsigned int VBO, VAO;
    Neon::NeonShader* shader = nullptr;

    Neon::NeonApp app;
    app.SetResourceRoot("D:/Workspace/Neon/res");
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
    shader = new Neon::NeonShader(app.GetResourceRoot() + "/shader/vertexShader.glsl", app.GetResourceRoot() + "/shader/fragmentShader.glsl");
        });

    app.OnUpdate([&]() {
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
