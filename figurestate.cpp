#include "figurestate.h"

void FigureState::setDefault()
{
    float defaultMatrix[DEFAULT_ROW][COL] = DEFAULT_MATRIX;

    for (int i = 0; i < DEFAULT_ROW; i ++) {
        for (int j = 0; j < COL; j ++) {
            figureMatrix[i][j] = defaultMatrix[i][j];
        }
    }
}

void FigureState::rotateX()
{
    change(ROTATE_X_ACTION);
}

void FigureState::rotateY()
{
    change(ROTATE_Y_ACTION);
}

void FigureState::rotateZ()
{
    change(ROTATE_Z_ACTION);
}

void FigureState::mirrowX()
{
    change(MIRROW_X_ACTION);
}

void FigureState::mirrowY()
{
    change(MIRROW_Y_ACTION);
}

void FigureState::moveUp()
{
    change(MOVE_UP_ACTION);
}

void FigureState::moveDown()
{
    change(MOVE_DOWN_ACTION);
}

void FigureState::moveLeft()
{
    change(MOVE_LEFT_ACTION);
}

void FigureState::moveRight()
{
    change(MOVE_RIGHT_ACTION);
}

void FigureState::scaleUpX()
{
    change(SCALE_UP_X_ACTION);
}

void FigureState::scaleDownX()
{
    change(SCALE_DOWN_X_ACTION);
}

void FigureState::scaleUpY()
{
    change(SCALE_UP_Y_ACTION);
}

void FigureState::scaleDownY()
{
    change(SCALE_DOWN_Y_ACTION);
}

void FigureState::change(const short axis)
{
    for (int i = 0; i < DEFAULT_ROW; i ++) {
        float * tmp = new float[COL];

        for (int j = 0; j < COL; j ++) {
            tmp[j] = 0;
            for (int k = 0; k < COL; k++) {
                tmp[j] += figureMatrix[i][k] * rotateMatrixes[axis][k][j];
            }
        }

        for (int j = 0; j < COL; j ++) {
            figureMatrix[i][j] = tmp[j];
        }
    }
}

