#pragma once
#pragma once
#include"Shapes/Shape.h"

class Square : public shape
{
private:
    Point Corner;
    int length;
public:
    Square(Point P1, int len, GfxInfo shapeGfxInfo);
    virtual void Draw(GUI* pUI) const;
};
