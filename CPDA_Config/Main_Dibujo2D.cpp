// Práctica 2
// Cadena Palafox Diego Aaron
// Fecha de entrega: 30 de Agosto del 2026
// Número de cuenta: 419047650

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    glfwInit();

    // Verificación de compatibilidad
    /*
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    */

    GLFWwindow* window = glfwCreateWindow(
        WIDTH,
        HEIGHT,
        "Práctica 2 Diego Cadena",
        NULL,
        NULL
    );

    glfwSetFramebufferSizeCallback(window, resize);

    // Verificación de errores de creación de ventana
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwSetFramebufferSizeCallback(window, resize);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    // Verificación de errores de inicialización de GLEW
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialise GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // Imprimimos información de OpenGL del sistema
    std::cout << "> Version: "
        << glGetString(GL_VERSION)
        << std::endl;

    std::cout << "> Vendor: "
        << glGetString(GL_VENDOR)
        << std::endl;

    std::cout << "> Renderer: "
        << glGetString(GL_RENDERER)
        << std::endl;

    std::cout << "> SL Version: "
        << glGetString(GL_SHADING_LANGUAGE_VERSION)
        << std::endl;

    // Define las dimensiones del viewport
    // glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

    float vertices[] =
    {
        // =========================================================
        // HABITACIÓN
        // =========================================================

        // Esquina vertical derecha
         0.35f,  1.00f, 0.0f,   0.0f, 0.0f, 0.0f,
         0.10f, -0.20f, 0.0f,   0.0f, 0.0f, 0.0f,

         // Línea pared derecha
          0.10f, -0.20f, 0.0f,   0.0f, 0.0f, 0.0f,
          1.00f, -0.75f, 0.0f,   0.0f, 0.0f, 0.0f,

          // Línea pared izquierda
           0.10f, -0.20f, 0.0f,   0.0f, 0.0f, 0.0f,
          -1.00f, -0.85f, 0.0f,   0.0f, 0.0f, 0.0f,

          // Línea horizontal pared derecha
           0.28f,  0.45f, 0.0f,   0.0f, 0.0f, 0.0f,
           1.00f,  0.52f, 0.0f,   0.0f, 0.0f, 0.0f,

           // Línea piso
            0.10f, -0.20f, 0.0f,   0.0f, 0.0f, 0.0f,

            // Quitar V5 o punto 6
            -0.45f, -1.00f, 0.0f,   0.0f, 0.0f, 0.0f,

            // Otra línea del piso
             0.10f, -0.20f, 0.0f,   0.0f, 0.0f, 0.0f,

             // Quitar P7 V10
              0.30f, -1.00f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // CUERPO DE LA GUITARRA
              // =========================================================

              // Centro
              -0.18f, -0.48f, 0.0f,   0.95f, 0.95f, 0.95f,

              // Contorno
              -0.35f, -0.05f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.05f, -0.10f, 0.0f,   0.95f, 0.95f, 0.95f,
               0.00f, -0.40f, 0.0f,   0.95f, 0.95f, 0.95f,
               0.20f, -0.60f, 0.0f,   0.95f, 0.95f, 0.95f,
               0.16f, -0.88f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.18f, -0.98f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.48f, -0.83f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.43f, -0.55f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.60f, -0.28f, 0.0f,   0.95f, 0.95f, 0.95f,
              -0.48f, -0.10f, 0.0f,   0.95f, 0.95f, 0.95f,

              -0.35f, -0.05f, 0.0f,   0.95f, 0.95f, 0.95f,


              // =========================================================
              // CONTORNO CUERPO
              // =========================================================

              -0.35f, -0.05f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.05f, -0.10f, 0.0f,   0.0f, 0.0f, 0.0f,
               0.00f, -0.40f, 0.0f,   0.0f, 0.0f, 0.0f,
               0.20f, -0.60f, 0.0f,   0.0f, 0.0f, 0.0f,
               0.16f, -0.88f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.18f, -0.98f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.48f, -0.83f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.43f, -0.55f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.60f, -0.28f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.48f, -0.10f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // BRAZO DE LA GUITARRA
              // =========================================================

              -0.40f, -0.05f, 0.0f,   0.75f, 0.75f, 0.70f,
              -0.31f, -0.03f, 0.0f,   0.75f, 0.75f, 0.70f,
              -0.55f,  0.70f, 0.0f,   0.75f, 0.75f, 0.70f,

              -0.31f, -0.03f, 0.0f,   0.75f, 0.75f, 0.70f,
              -0.55f,  0.70f, 0.0f,   0.75f, 0.75f, 0.70f,
              -0.63f,  0.70f, 0.0f,   0.75f, 0.75f, 0.70f,

              // Sombreado
              -0.40f, -0.05f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.31f, -0.03f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.55f,  0.70f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.63f,  0.70f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // TRASTES
              // =========================================================

              -0.405f, 0.02f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.335f, 0.02f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.425f, 0.08f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.350f, 0.08f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.445f, 0.14f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.370f, 0.14f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.465f, 0.20f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.390f, 0.20f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.485f, 0.26f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.410f, 0.26f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.505f, 0.32f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.430f, 0.32f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.525f, 0.38f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.450f, 0.38f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.545f, 0.44f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.470f, 0.44f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.565f, 0.50f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.490f, 0.50f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.585f, 0.56f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.510f, 0.56f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.605f, 0.62f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.530f, 0.62f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.620f, 0.67f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.545f, 0.67f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // CABEZA DE LA GUITARRA
              // GL_TRIANGLE_FAN
              // =========================================================

              // Centro
              -0.67f, 0.80f, 0.0f,   0.85f, 0.85f, 0.80f,

              -0.63f, 0.69f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.75f, 0.80f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.76f, 0.95f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.58f, 0.94f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.52f, 0.76f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.55f, 0.70f, 0.0f,   0.85f, 0.85f, 0.80f,
              -0.63f, 0.69f, 0.0f,   0.85f, 0.85f, 0.80f,


              // =========================================================
              // CONTORNO CABEZA
              // =========================================================

              -0.63f, 0.69f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.75f, 0.80f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.76f, 0.95f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.58f, 0.94f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.52f, 0.76f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.55f, 0.70f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // BOCA NEGRA
              // =========================================================

              -0.20f, -0.42f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.28f, -0.42f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.25f, -0.34f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.18f, -0.31f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.11f, -0.34f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.07f, -0.41f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.08f, -0.50f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.16f, -0.55f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.24f, -0.51f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.28f, -0.42f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // PUENTE
              // =========================================================

              -0.25f, -0.69f, 0.0f,   0.0f, 0.0f, 0.0f,
               0.02f, -0.61f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.01f, -0.70f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.25f, -0.69f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.01f, -0.70f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.20f, -0.77f, 0.0f,   0.0f, 0.0f, 0.0f,


              // =========================================================
              // CUERDAS CABEZA
              // =========================================================

              -0.70f, 0.91f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.58f, 0.74f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.66f, 0.91f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.55f, 0.75f, 0.0f,   0.0f, 0.0f, 0.0f,

              -0.62f, 0.91f, 0.0f,   0.0f, 0.0f, 0.0f,
              -0.53f, 0.76f, 0.0f,   0.0f, 0.0f, 0.0f
    };


    // =============================================================
    // CREACIÓN DE BUFFERS
    // =============================================================

    GLuint VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Enlazar Vertex Array Object
    glBindVertexArray(VAO);

    // Copiamos nuestro arreglo de vértices
    // en un buffer de vértices para que OpenGL lo use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );


    // =============================================================
    // CARACTERÍSTICAS DE LOS VÉRTICES
    // =============================================================

    // Posición
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(GLfloat),
        (GLvoid*)0
    );

    glEnableVertexAttribArray(0);


    // Color
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(GLfloat),
        (GLvoid*)(3 * sizeof(GLfloat))
    );

    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


    // =============================================================
    // GROSOR DE LAS LÍNEAS
    // =============================================================

    glLineWidth(2.0f);


    // =============================================================
    // CICLO PRINCIPAL
    // =============================================================

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // =========================================================
        // RENDER
        // =========================================================

        // Limpiar el buffer de color
        glClearColor(
            1.0f,
            1.0f,
            1.0f,
            1.0f
        );

        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.Use();

        glBindVertexArray(VAO);


        // =========================================================
        // HABITACIÓN
        // =========================================================

        glLineWidth(1.5f);

        glDrawArrays(
            GL_LINES,
            0,
            12
        );


        // =========================================================
        // CUERPO GUITARRA
        // =========================================================

        glDrawArrays(
            GL_TRIANGLE_FAN,
            12,
            12
        );


        // =========================================================
        // CONTORNO CUERPO
        // =========================================================

        glLineWidth(3.0f);

        glDrawArrays(
            GL_LINE_LOOP,
            24,
            10
        );


        // =========================================================
        // BRAZO
        // =========================================================

        glDrawArrays(
            GL_TRIANGLES,
            34,
            6
        );


        // =========================================================
        // CONTORNO BRAZO
        // =========================================================

        glDrawArrays(
            GL_LINE_LOOP,
            40,
            4
        );


        // =========================================================
        // TRASTES
        // =========================================================

        glLineWidth(2.0f);

        glDrawArrays(
            GL_LINES,
            44,
            24
        );


        // =========================================================
        // CABEZA GUITARRA
        // =========================================================

        glDrawArrays(
            GL_TRIANGLE_FAN,
            68,
            8
        );


        // =========================================================
        // CONTORNO CABEZA
        // =========================================================

        glLineWidth(3.0f);

        glDrawArrays(
            GL_LINE_LOOP,
            76,
            6
        );


        // =========================================================
        // BOCA DE LA GUITARRA
        // =========================================================

        glDrawArrays(
            GL_TRIANGLE_FAN,
            82,
            10
        );


        // =========================================================
        // PUENTE
        // =========================================================

        glDrawArrays(
            GL_TRIANGLES,
            92,
            6
        );


        // =========================================================
        // CUERDAS DE LA CABEZA
        // =========================================================

        glLineWidth(2.0f);

        glDrawArrays(
            GL_LINES,
            98,
            6
        );


        // Desenlazar VAO
        glBindVertexArray(0);

        // Intercambiar buffers
        glfwSwapBuffers(window);
    }


    // =============================================================
    // FINALIZAR GLFW
    // =============================================================

    glfwTerminate();

    return EXIT_SUCCESS;
}


// ================================================================
// FUNCIÓN RESIZE
// ================================================================

void resize(GLFWwindow* window, int width, int height)
{
    // Establecer el Viewport al tamaño de la ventana creada
    glViewport(
        0,
        0,
        width,
        height
    );

    // glViewport(0, 0, screenWidth, screenHeight);
}