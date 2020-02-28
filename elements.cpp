#include "elements.h"
#include "helper.h"

Elements::Elements()
{ 
}

void Elements::renderCoordinateSystem()
{
    float r, g, b;

    glBegin(GL_LINES);
    Helper::qColorToRGB(Qt::red, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    Helper::qColorToRGB(Qt::red, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, 0.0f);
    glEnd();
}

void Elements::renderFigure()
{
    float r, g, b;

    glBegin(GL_LINE_LOOP);
    Helper::qColorToRGB(Qt::green, r, g, b);
    glColor3f(r, g, b);
    glVertex3f(state.figureMatrix[0][0], state.figureMatrix[0][1], state.figureMatrix[0][2]);
    glVertex3f(state.figureMatrix[1][0], state.figureMatrix[1][1], state.figureMatrix[1][2]);
    glVertex3f(state.figureMatrix[2][0], state.figureMatrix[2][1], state.figureMatrix[2][2]);
    glVertex3f(state.figureMatrix[3][0], state.figureMatrix[3][1], state.figureMatrix[3][2]);
    glEnd();
}

