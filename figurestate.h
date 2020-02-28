#ifndef FIGURESTATE_H
#define FIGURESTATE_H

#define DEFAULT_MATRIX {{-0.8f, 0.8f, 0.0f}, {0.8f, -0.8f, 0.0f}, {-0.5f, -0.5f, 0.0f}, {-0.8f, 0.2f, 0.0f}}
#define DEFAULT_ROW 4
#define ROW 3
#define COL 3

#include <QObject>
#include <qmath.h>

QT_BEGIN_NAMESPACE
namespace Ui { class FigureState; }
QT_END_NAMESPACE

class FigureState : public QObject
{
    Q_OBJECT

public:
    const static short ROTATE_X_ACTION   = 0;
    const static short ROTATE_Y_ACTION   = 1;
    const static short ROTATE_Z_ACTION   = 2;
    const static short MIRROW_X_ACTION   = 3;
    const static short MIRROW_Y_ACTION   = 4;
    const static short MOVE_UP_ACTION    = 5;
    const static short MOVE_DOWN_ACTION  = 6;
    const static short MOVE_LEFT_ACTION  = 7;
    const static short MOVE_RIGHT_ACTION = 8;
    const static short SCALE_UP_X_ACTION = 9;
    const static short SCALE_DOWN_X_ACTION = 10;
    const static short SCALE_UP_Y_ACTION = 11;
    const static short SCALE_DOWN_Y_ACTION = 12;

    float figureMatrix[DEFAULT_ROW][COL] = DEFAULT_MATRIX;

    static FigureState& Instance()
    {
        static FigureState theSingleInstance;

        return theSingleInstance;
    }

public Q_SLOTS:
    void setDefault();
    void rotateX();
    void rotateY();
    void rotateZ();
    void mirrowX();
    void mirrowY();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void scaleUpX();
    void scaleDownX();
    void scaleUpY();
    void scaleDownY();

private:
    const float degree = 15 * M_PI / 180;
    const float moveStep = 0.1;
    const float scaleStep = 0.1;

    const float rotateMatrixes[13][ROW][COL] = {
        // rotateX
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, (float) cos(degree), (float) -sin(degree)},
            {0.0f, (float) sin(degree), (float) cos(degree)},
        },
        // rotateY
        {
            {(float) cos(degree), 0.0f, (float) sin(degree)},
            {0.0f, 1.0f, 0.0f},
            {(float) -sin(degree), 0.0f, (float) cos(degree)},
        },
        // rotateZ
        {
            {(float) cos(degree), (float) -sin(degree), 0.0f},
            {(float) sin(degree), (float) cos(degree), 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // mirrowX
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // mirrowY
        {
            {-1.0f, 0.0f, 0.0f},
            {0.0f, -1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // moveUp
        {
            {1.0f, 0.1f, 0.1f},
            {0.1f, 1.0f, 0.1f},
            {0.1f, 0.1f, 1.0f},
        },
        // moveDown
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // moveLeft
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // moveRight
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // scaleUpX
        {
            {1.0f + scaleStep, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // scaleDownX
        {
            {1.0f - scaleStep, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // scaleUpY
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f + scaleStep, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
        // scaleDownY
        {
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f - scaleStep, 0.0f},
            {0.0f, 0.0f, 1.0f},
        },
    };

    FigureState(){}
    FigureState(const FigureState& root) = delete;
    FigureState& operator = (const FigureState&) = delete;

    void change(short actionMatrixCode);
};

#endif // FIGURESTATE_H
