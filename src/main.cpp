#include <Neon/Neon.h>
#include <Neon/Core/NeonApp.h>
#include <Neon/Core/NeonWindow.h>
#include <Neon/GraphicsAPI/Shader/NeonShader.h>

#include <iostream>
#include "shader.h"

int main() {
    Neon::NeonWindow* window1 = nullptr;
    Neon::NeonShader* shader1 = nullptr;
    unsigned int VBO1, VAO1;

    Neon::NeonWindow* window2 = nullptr;
    Neon::NeonShader* shader2 = nullptr;
    unsigned int VBO2, VAO2;

    Neon::NeonApp app;
    app.SetResourceRoot("D:/Workspace/Neon/res");

    app.OnInitialize([&]() {

        window1 = app.CreateNeonWindow(1024, 768, "Neon1");
    {
        // Define the vertices of the triangle
        float vertices[] = {
             0.0f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
        };

        // Create the vertex buffer object and vertex array object
        glGenBuffers(1, &VBO1);
        glGenVertexArrays(1, &VAO1);

        // Bind the vertex array object and vertex buffer object
        glBindVertexArray(VAO1);
        glBindBuffer(GL_ARRAY_BUFFER, VBO1);

        // Copy the vertices data into the vertex buffer object
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Specify the vertex attribute pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Create the shader program
        shader1 = new Neon::NeonShader(app.GetResourceRoot() + "/shader/vertexShader.glsl", app.GetResourceRoot() + "/shader/fragmentShader.glsl");
    }

    window2 = app.CreateNeonWindow(1024, 768, "Neon2");
    {
        // Define the vertices of the triangle
        float vertices[] = {
             0.0f,  0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
        };

        // Create the vertex buffer object and vertex array object
        glGenBuffers(1, &VBO2);
        glGenVertexArrays(1, &VAO2);

        // Bind the vertex array object and vertex buffer object
        glBindVertexArray(VAO2);
        glBindBuffer(GL_ARRAY_BUFFER, VBO2);

        // Copy the vertices data into the vertex buffer object
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Specify the vertex attribute pointers
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Create the shader program
        shader2 = new Neon::NeonShader(app.GetResourceRoot() + "/shader/vertexShader.glsl", app.GetResourceRoot() + "/shader/fragmentShader.glsl");
    }
        });




    app.OnUpdate([&](Neon::NeonWindow* window, float timeDelta) {
        if (window == window1)
        {
            // Clear the screen
            glClearColor(0.3f, 0.5f, 0.7f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Draw the triangle
            shader1->use();
            glBindVertexArray(VAO1);
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
    if (window == window2)
    {
        // Clear the screen
        glClearColor(0.7f, 0.5f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw the triangle
        shader1->use();
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
        });






    app.OnTerminate([&]() {
        SAFE_DELETE(shader1);
    SAFE_DELETE(shader2);

    // Cleanup
    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);
    glDeleteVertexArrays(2, &VAO1);
    glDeleteBuffers(2, &VBO1);
        });

    app.Run();

    return 0;
}
