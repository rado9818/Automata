#include "CDeterminateFiniteAutomaton.h"
#include <iostream>
#include <cassert>
CDeterminateFiniteAutomaton::CDeterminateFiniteAutomaton()
{
    //ctor
}

CDeterminateFiniteAutomaton::~CDeterminateFiniteAutomaton()
{
    //dtor
}

CDeterminateFiniteAutomaton::CDeterminateFiniteAutomaton(const CDeterminateFiniteAutomaton& other)
{
    //copy ctor
}

CDeterminateFiniteAutomaton& CDeterminateFiniteAutomaton::operator=(const CDeterminateFiniteAutomaton& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::istream& CDeterminateFiniteAutomaton::inserter(std::istream& in){
    std::cout<<"Please enter the number of states in the automata:\n";
    in>>numStates;
    in.ignore();
    states = new CState*[numStates];
    for(unsigned i=0; i<numStates; i++){
        states[i] = new CState();
        in>>*states[i];
    }
    return in;

}

 std::istream& operator >>(std::istream& in, CDeterminateFiniteAutomaton& rhs){
    rhs.inserter(in);
    return in;
}

unsigned CDeterminateFiniteAutomaton::getNumStates() const{
    return numStates;
}

