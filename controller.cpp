#include "controller.h"
#include "operations\opAddRect.h"
#include "opAddSquare.h"  
#include"opAddCircle.h"
//Constructor
controller::controller()
{
    pGraph = new Graph;
    pGUI = new GUI;    
}


operationType controller::GetUseroperation() const
{
   
    return pGUI->GetUseroperation();
}


operation* controller::createOperation(operationType OpType)
{
    operation* pOp = nullptr;

    
    switch (OpType)
    {
    case DRAW_RECT:
        pOp = new opAddRect(this);
        break;

    case DRAW_SQU:  
        pOp = new opAddSquare(this);
        break;

    case DRAW_CIRC:  
        pOp = new opAddCircle(this);
        break;

    case EXIT:
        

        break;

    case STATUS:    
        break;
    }

    return pOp;

}


void controller::UpdateInterface() const
{
    pGraph->Draw(pGUI);
}

GUI* controller::GetUI() const
{
    return pGUI;
}

Graph* controller::getGraph() const
{
    return pGraph;
}

//Destructor
controller::~controller()
{
    delete pGUI;
    delete pGraph;
}


void controller::Run()
{
    operationType OpType;
    do
    {
       
        OpType = GetUseroperation();

        
        operation* pOpr = createOperation(OpType);

        
        if (pOpr)
        {
            pOpr->Execute();
            delete pOpr;    
            pOpr = nullptr;
        }

        
        UpdateInterface();

    } while (OpType != EXIT);

}