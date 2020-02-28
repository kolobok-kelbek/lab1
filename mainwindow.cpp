#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_default,  SIGNAL(released()), &state, SLOT(setDefault()));

    connect(ui->pushButton_rotateX,  SIGNAL(released()), &state, SLOT(rotateX()));
    connect(ui->pushButton_rotateY,  SIGNAL(released()), &state, SLOT(rotateY()));
    connect(ui->pushButton_rotateZ,  SIGNAL(released()), &state, SLOT(rotateZ()));

    connect(ui->pushButton_mirrorX,  SIGNAL(released()), &state, SLOT(mirrowX()));
    connect(ui->pushButton_mirrorY,  SIGNAL(released()), &state, SLOT(mirrowY()));

    connect(ui->pushButton_top,  SIGNAL(released()), &state, SLOT(moveUp()));
    connect(ui->pushButton_bottom,  SIGNAL(released()), &state, SLOT(moveDown()));
    connect(ui->pushButton_left,  SIGNAL(released()), &state, SLOT(moveLeft()));
    connect(ui->pushButton_right,  SIGNAL(released()), &state, SLOT(moveRight()));

    connect(ui->pushButton_scaleUpX,  SIGNAL(released()), &state, SLOT(scaleUpX()));
    connect(ui->pushButton_scaleDownX,  SIGNAL(released()), &state, SLOT(scaleDownX()));
    connect(ui->pushButton_scaleUpY,  SIGNAL(released()), &state, SLOT(scaleUpY()));
    connect(ui->pushButton_scaleDownY,  SIGNAL(released()), &state, SLOT(scaleDownY()));

    tmr = new QTimer(this);
    tmr->setInterval(50);

    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));

    tmr->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    ui->openGLWidget->update();
//    if (isRotateX) {
//        handleRotate(0, 1);
//    }

//    if (isRotateY) {
//        handleRotate(0, 2);
//    }

//    if (isRotateZ) {
//        handleRotate(1, 2);
//    }
}
