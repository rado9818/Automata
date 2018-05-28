#include "CState.h"

CState::CState()
{
    //ctor
    isInitial = false;
    isFinal = false;
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

std::ostream& operator <<(std::ostream& out, CState &rhs){
    rhs.extractor(out);
    return out;
}
std::istream& CState::inserter(std::istream& in){
    name = new char[100];
    std::cout<<"Enter the state's name\n";
    in.getline(name, 99);
    return in;
}

std::ostream& CState::extractor(std::ostream& out){
    out<<"State's name: "<<name<<std::endl;
    out<<"Is state initial: "<<(isInitial ? "Yes" : "No")<<std::endl;
    out<<"Is state final: "<<(isFinal ? "Yes" : "No")<<std::endl<<std::endl;
    return out;
}
