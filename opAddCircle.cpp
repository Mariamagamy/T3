#include "opAddCircle.h"
#include "controller.h" 
#include "GUI/GUI.h"
#include "Shapes/Graph.h"
#include "Circle.h"

opAddCircle::opAddCircle(controller* pCont) : operation(pCont) {}

void opAddCircle::Execute()
{
    Point P1;

    
    GUI* pGUI = pControl->GetUI();
    pGUI->PrintMessage("New Circle: Click at center");

    
    pGUI->GetPointClicked(P1.x, P1.y);

    pGUI->PrintMessage("Enter the radius of the circle");
    int radius = stoi(pGUI->GetSrting());

    GfxInfo CircleGfxInfo;
    
    CircleGfxInfo.DrawClr = pGUI->getCrntDrawColor();
    CircleGfxInfo.FillClr = pGUI->getCrntFillColor();
    CircleGfxInfo.BorderWdth = pGUI->getCrntPenWidth();

    CircleGfxInfo.isFilled = false;    
    CircleGfxInfo.isSelected = false;    

    
    Circle* C = new Circle(P1, radius, CircleGfxInfo);

    
    Graph* pGr = pControl->getGraph();

   
    pGr->Addshape(C);
}
