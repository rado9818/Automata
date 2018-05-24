#include "CState.h"

CState::CState()
{
    //ctor
}

CState::~CState()
{
    //dtor
}

CState::CState(const CState& other)
{
    //copy ctor
}

CState& CState::operator=(const CState& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
