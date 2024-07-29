#pragma once
#include"operations/operation.h"
class opAddSquare : public operation
{
public:
    opAddSquare(controller* pCont);
    virtual void Execute();
};
