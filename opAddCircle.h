#pragma once
#pragma once
#include "operations/operation.h"

class opAddCircle : public operation
{
public:
    opAddCircle(controller* pCont);
    virtual void Execute();
};
