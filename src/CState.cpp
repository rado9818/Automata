#include "CState.h"

CState::CState(unsigned id)
{
    //ctor
    this->id = id;
    isInitial = false;
    isFinal = false;
}

CState::CState(unsigned id, char* name)
{
    //ctor
    this->id = id;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);

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

unsigned CState::getId() const{
    return id;
}

int CState::setId(unsigned id){
    this->id = id;
    return 0;
}

char* CState::getName() const{
    return name;
}

int CState::setIsInitial(bool isInitial, CState** states, unsigned numStates, unsigned line) throw (AutomatonException){
    for(unsigned i=0; i<numStates; i++){
        if(states[i]->getIsInitial()){
            throw AutomatonException(states[i]->getName(), line);
        }
    }
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
