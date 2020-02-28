#ifndef HELPER_H
#define HELPER_H

#include <QColor>

#define RGB_MIN 1
#define RGB_MAX 255

class Helper
{
public:
    Helper();
    static void qColorToRGB(const QColor &C, float &r, float &g, float &b) {
        r = normalize_0_1(C.red(), RGB_MIN, RGB_MAX);
        g = normalize_0_1(C.green(), RGB_MIN, RGB_MAX);
        b = normalize_0_1(C.blue(), RGB_MIN, RGB_MAX);
    };

    static float normalize_0_1(float val, float min, float max) {
        return (val - min) / (max - min);
    };
};

#endif // HELPER_H
