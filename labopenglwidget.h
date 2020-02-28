#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QColor>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "elements.h"

class LabOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{

    Q_OBJECT;
private:
    Elements elements = *new Elements();
public:
    LabOpenGLWidget(QWidget *parent = nullptr);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // MYOPENGLWIDGET_H
