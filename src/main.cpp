#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <GLFW/glfw3.h>

static GLfloat right_view_rotx = 0.05f, left_view_rotx = -0.05f, up_view_roty = 0.05f ,down_view_roty = -0.05f ,view_rotz=0.05f , PLUS = 0.06f;


/* change view angle, exit upon ESC */
void key( GLFWwindow* window, int k, int s, int action, int mods )
{
  if( action != GLFW_PRESS ) return;

  switch (k) {
  case GLFW_KEY_Z:
    if( mods & GLFW_MOD_SHIFT )
      view_rotz -= 0.1;
    else
      right_view_rotx = 0.05f; left_view_rotx = -0.05f; up_view_roty = 0.05f; down_view_roty = -0.05f;
    break;
  case GLFW_KEY_ESCAPE:
    glfwSetWindowShouldClose(window, true);
    break;
  case GLFW_KEY_UP:
    up_view_roty += PLUS;
    down_view_roty +=  PLUS;
    break;
  case GLFW_KEY_DOWN:
    up_view_roty += -PLUS;
    down_view_roty += - PLUS;
    break;
  case GLFW_KEY_LEFT:
    right_view_rotx += - PLUS;
    left_view_rotx += -PLUS;
    break;
  case GLFW_KEY_RIGHT:
    right_view_rotx += PLUS;
    left_view_rotx += PLUS;
    break;
  default:
    return;
  }
}



int main(void)
{



    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Hello GLFW !", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

// Set callback functions
glfwSetKeyCallback(window, key);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
// цвет фона 
glClearColor(0.0, 0.0, 1.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT);

// цвет квадратика
glColor3f(0.0, 1.0, 0.0);

// обычное 2D  (без изометрии)
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

// рисуем квадратик 
glBegin(GL_POLYGON);
glVertex2f(left_view_rotx, down_view_roty);
glVertex2f(left_view_rotx, up_view_roty);
glVertex2f(right_view_rotx, up_view_roty);
glVertex2f(right_view_rotx, down_view_roty);
glEnd();


// цвет крестика
glColor3f(1.0, 1.0, 1.0);

// рисуем горизонтальную линию  
glBegin(GL_LINES);
glVertex2f(0.03f, 0.0f);
glVertex2f(-0.03f, 0.0f);
glEnd();

// рисуем вертикальную линию  
glBegin(GL_LINES);
glVertex2f(0.0f, 0.03f);
glVertex2f(0.0f, -0.03f);
glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}