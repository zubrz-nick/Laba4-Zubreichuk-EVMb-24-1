// lab 1 zubr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define GLFW_DLL
#define GLEW_DLL
#include <iostream>
#include "glew-2.1.0/include/GL/glew.h"
#include "glfw-3.4.bin.WIN64/include/GLFW/glfw3.h"


int main()
{

    glfwInit();
    if (!glfwInit())
    {
        fprintf(stderr, "ERROR GLFW Init: \n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1.0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0.0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    while (!glfwWindowShouldClose(Okno))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0, 0.4, 0.1, 1.0);

        glBegin(GL_QUADS);
        glColor3f(0.7, 0.1, 0.6);  glVertex2f(0.5, -0.25);
        glColor3f(0.7, 0.1, 0.6);  glVertex2f(-0.5, -0.25);
        glColor3f(0.7, 0.1, 0.6);  glVertex2f(-0.3, 0.25);
        glColor3f(0.7, 0.1, 0.6);  glVertex2f(0.3, 0.25);
        glEnd();
        glfwSwapBuffers(Okno);

        glfwPollEvents();
    }
    glfwTerminate();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
