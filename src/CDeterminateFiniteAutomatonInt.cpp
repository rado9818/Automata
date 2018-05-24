#include "CDeterminateFiniteAutomatonInt.h"

CDeterminateFiniteAutomatonInt::CDeterminateFiniteAutomatonInt()
{
    //ctor
}

CDeterminateFiniteAutomatonInt::~CDeterminateFiniteAutomatonInt()
{
    //dtor
}

CDeterminateFiniteAutomatonInt::CDeterminateFiniteAutomatonInt(const CDeterminateFiniteAutomatonInt& other)
{
    //copy ctor
}

CDeterminateFiniteAutomatonInt& CDeterminateFiniteAutomatonInt::operator=(const CDeterminateFiniteAutomatonInt& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


std::istream& CDeterminateFiniteAutomatonInt::inserter(std::istream& in){
    CDeterminateFiniteAutomaton::inserter(in);
    std::cout<<"Enter the number of symbols in the alphabet\n";

    //enter the alphabet
    in>>numSymbols;
    alphabet = new int[numSymbols];
    for(unsigned i=0; i<numSymbols; i++){
        std::cout<<"Enter the "<<i+1<<" letter: ";
        in>>alphabet[i];
    }

    //enter the transitions
  /*  transitions = new char**[alphabet];
    for(unsigned i=0; i<alphabet; i++){
        transitions = new char*[numStates];
    }*/
    in.ignore();
    for(unsigned i=0; i<getNumStates(); i++){
        for(unsigned j=0; j<numSymbols; j++){
            std::cout<<"Enter ("<<states[i]->getName()<<", "<<alphabet[j]<<")";
            char *transition = new char[100];
            in.getline(transition, 99);
        }
    }
    return in;

}

 std::istream& operator >>(std::istream& in, CDeterminateFiniteAutomatonInt& rhs){
    rhs.inserter(in);
    return in;
}
