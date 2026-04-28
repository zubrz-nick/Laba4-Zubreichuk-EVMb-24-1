
#define GLFW_DLL
#define GLEW_DLL
#include <iostream>
#include "glew-2.1.0/include/GL/glew.h"
#include "glfw-3.4.bin.WIN64/include/GLFW/glfw3.h"
#include "Shader.h"


float vertex[] = 
{
    0.5, -0.25, 0.0,
    -0.5, -0.25, 0.0,
    -0.3, 0.25, 0.0,
    0.3, 0.25, 0.0
};

float points[] =
{
    0.5, -0.25, 0.0,
    -0.5, -0.25, 0.0,
    -0.3, 0.25, 0.0,
    0.3, 0.25, 0.0
};
GLuint indices[] =
{
    0, 1, 2,
    0, 2, 3
};
int main()
{

    glfwInit();
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR GLFW Init: \n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* Okno;
    Okno = glfwCreateWindow(512, 512, "Okno", NULL, NULL);

    if (!Okno) 
    {
        glfwTerminate();

    }
    glfwMakeContextCurrent(Okno);

    
    GLenum ret = glewInit();
    if (GLEW_OK != ret)
    {
        fprintf(stderr, "ERROR GLEW Init: \n", glewGetErrorString (ret));
        return -2;
    }

    GLuint VAO, VBO, EBO;
    
    glCreateBuffers(1, &VBO);
    glCreateVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    Shader shader("shader.vert", "shader.frag");

    while (!glfwWindowShouldClose(Okno))
    {
        
        glClearColor(1.0, 0.4, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        

        shader.use();

        float red = fabs(sin(glfwGetTime()));   
        float green = fabs(cos(glfwGetTime()));   
        float blue = fabs(sin(glfwGetTime())); 

        shader.setVec4("ourColor", red, green, blue, 1.0f);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(Okno);

        glfwPollEvents();
    }
    glfwTerminate();
}
