#include "Square.h"
#include "GUI/GUI.h"

Square::Square(Point P1, int len, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
    Corner = P1;
    length = len;
}

void Square::Draw(GUI* pUI) const
{
    // Call Output::DrawSquare to draw a square on the screen
    pUI->DrawSquare(Corner, length, ShpGfxInfo);
}
