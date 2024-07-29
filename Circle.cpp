#include "Circle.h"
#include "GUI/GUI.h"

Circle::Circle(Point P1, int r, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
    Center = P1;
    radius = r;
}

void Circle::Draw(GUI* pUI) const
{
    
    pUI->DrawCircle(Center, radius, ShpGfxInfo);
}
