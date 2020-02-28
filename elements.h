#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QOpenGLFunctions>
#include "figurestate.h"

class Elements
{

private:
   FigureState& state = FigureState::Instance();

public:
    Elements();
    void renderCoordinateSystem();
    void renderFigure();
};

#endif // ELEMENTS_H
