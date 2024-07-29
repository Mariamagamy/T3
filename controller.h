#pragma once

#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"

class operation; 
class controller
{
    Graph* pGraph;    
    GUI* pGUI;        

public:
    controller();
    ~controller();

    
    operationType GetUseroperation() const;
    operation* createOperation(operationType); 
    void Run();

    Graph* getGraph() const;

   
    GUI* GetUI() const; 
    void UpdateInterface() const;       

};