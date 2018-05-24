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

char* CState::getName() const{
    return name;
}

int CState::setIsInitial(bool isInitial){
    this->isInitial = isInitial;
    return 0;
}

int CState::setIsFinal(bool isFinal){
    this->isFinal = isFinal;
    return 0;
}

bool CState::getIsInitial() const{
    return isInitial;
}

bool CState::getIsFinal() const{
    return isFinal;
}
std::istream& operator >>(std::istream& in, CState &rhs){
    rhs.inserter(in);
    return in;
}
std::istream& CState::inserter(std::istream& in){
    name = new char[100];
    std::cout<<"Enter the state's name\n";
    in.getline(name, 99);
    return in;
}
