#include "labopenglwidget.h"
#include "helper.h"
#include "elements.h"

LabOpenGLWidget::LabOpenGLWidget(QWidget *parent)
    : QOpenGLWidget { parent }
{

}

void LabOpenGLWidget::initializeGL()
{
    float r, g, b, a = Helper::normalize_0_1(RGB_MAX, RGB_MIN, RGB_MAX);
    initializeOpenGLFunctions();
    Helper::qColorToRGB(Qt::black, r, g, b);
    glClearColor(r, g, b, a);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void LabOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    elements.renderCoordinateSystem();
    elements.renderFigure();
}

void LabOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
