#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmath.h>
#include <QString>
#include <QTimer>
#include <QDebug>
#include "figurestate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
   FigureState& state = FigureState::Instance();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public Q_SLOTS:
    void updateTime();

private:
    bool isRotateX = false;
    bool isRotateY = false;
    bool isRotateZ = false;

    Ui::MainWindow *ui;
    QTimer *tmr;
};
#endif // MAINWINDOW_H
