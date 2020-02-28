#ifndef FIGURE_H
#define FIGURE_H

#include "figurestate.h";

class Figure
{
public:
    FigureState* state;

    static Figure& Instance()
    {
        static Figure theSingleInstance;

        return theSingleInstance;
    }

private:
    Figure& operator = (const Figure&) = delete;

};

#endif // FIGURE_H
