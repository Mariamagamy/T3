#include "opAddSquare.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include "Square.h"
#include"controller.h"
opAddSquare::opAddSquare(controller* pCont) : operation(pCont) {}

void opAddSquare::Execute()
{
    Point P1;

    // Get a pointer to the input / output interfaces
    GUI* pGUI = pControl->GetUI();
    pGUI->PrintMessage("New Square: Click at top left corner");

    // Read the corner and store in point P1
    pGUI->GetPointClicked(P1.x, P1.y);

    pGUI->PrintMessage("Enter the side length of the square");
    int length = stoi(pGUI->GetSrting());

    GfxInfo SquareGfxInfo;
    //get drawing, filling colors and pen width from the interface
    SquareGfxInfo.DrawClr = pGUI->getCrntDrawColor();
    SquareGfxInfo.FillClr = pGUI->getCrntFillColor();
    SquareGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

    SquareGfxInfo.isFilled = false;    //default is not filled
    SquareGfxInfo.isSelected = false;    //default is not selected

    // Create a square with the above parameters
    Square* S = new Square(P1, length, SquareGfxInfo);

    // Get a pointer to the graph
    Graph* pGr = pControl->getGraph();

    // Add the square to the list of shapes
    pGr->Addshape(S);
}
