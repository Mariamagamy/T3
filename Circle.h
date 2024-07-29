#pragma once
#pragma once
#include "Shapes/Shape.h"

class Circle : public shape
{
private:
    Point Center;
    int radius;
public:
    Circle(Point P1, int r, GfxInfo shapeGfxInfo);
    virtual void Draw(GUI* pUI) const;
};
