#include "CDeterminateFiniteAutomaton.h"
#include <iostream>
#include <cstring>
#include <cassert>
CDeterminateFiniteAutomaton::CDeterminateFiniteAutomaton()
{
    //ctor
}

CDeterminateFiniteAutomaton::~CDeterminateFiniteAutomaton()
{
    //dtor
    for(unsigned i=0; i<numStates; i++){
        if(states[i]!=NULL){
            delete[] states[i];
        }
    }
    for(unsigned i=0; i<numStates; i++){
        for(unsigned j=0; j<numSymbols; j++){
            if(transitions[i][j]!=NULL){
                delete[] transitions[i][j];
            }
        }
    }

    if(states!=NULL){
        delete states;
    }
}

CDeterminateFiniteAutomaton::CDeterminateFiniteAutomaton(const CDeterminateFiniteAutomaton& rhs)
{
    //copy ctor
    states = new CState*[rhs.numStates];
    for(unsigned i=0; i<rhs.numStates; i++){
        states[i] = rhs.states[i];
    }


    numStates = rhs.numStates;
    numSymbols = rhs.numSymbols;
    transitions = new char**[rhs.numStates];
    for(unsigned i=0; i<rhs.numStates; i++){
        transitions[i] = new char*[rhs.numSymbols];
    }

    for(unsigned i=0; i<rhs.numStates; i++){
        for(unsigned j=0; j<rhs.numSymbols; j++){
            strcpy(transitions[i][j], rhs.transitions[i][j]);
        }
    }
}

CDeterminateFiniteAutomaton& CDeterminateFiniteAutomaton::operator=(const CDeterminateFiniteAutomaton& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    states = new CState*[rhs.numStates];
    for(unsigned i=0; i<rhs.numStates; i++){
        states[i] = rhs.states[i];
    }

    numStates = rhs.numStates;
    numSymbols = rhs.numSymbols;
    transitions = new char**[rhs.numStates];
    for(unsigned i=0; i<rhs.numStates; i++){
        transitions[i] = new char*[rhs.numSymbols];
    }

    for(unsigned i=0; i<rhs.numStates; i++){
        for(unsigned j=0; j<rhs.numSymbols; j++){
            strcpy(transitions[i][j], rhs.transitions[i][j]);
        }
    }
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

int CDeterminateFiniteAutomaton::initializeTransitions(unsigned numSymbols){
    this->numSymbols = numSymbols;
    transitions = new char**[numStates];
    for(unsigned i=0; i<numSymbols; i++){
        transitions[i] = new char*[numSymbols];
    }
    return 0;
}

std::istream& CDeterminateFiniteAutomaton::insertTransitions(std::istream& in, CDeterminateFiniteAutomaton* rhs){
    in.ignore();
    char *alphabet = rhs->getAlphabetToChar();
    for(unsigned i=0; i<getNumStates(); i++){
        for(unsigned j=0; j<rhs->getNumSymbols(); j++){
            std::cout<<"Enter ("<<states[i]->getName()<<", "<<alphabet[j]<<"): ";
            char *transition = new char[100];
            in.getline(transition, 99);
            addTransition(transition, i, j);
        }
    }
    std::cout<<"Enter initial state\n";
    char *transition = new char[100];
    in.getline(transition, 99);
    CState& s = getStateFromName(transition);
    s.setIsInitial(true);

    std::cout<<"Enter the number of final states\n";
    unsigned numFinalStates;
    in>>numFinalStates;
    in.ignore();
    for(unsigned i=0; i<numFinalStates; i++){
        std::cout<<"Enter the "<<i+1<<" final state\n";
        in.getline(transition, 99);
        s = getStateFromName(transition);
        s.setIsFinal(true);
    }
    return in;
}
int CDeterminateFiniteAutomaton::addTransition(char* transition, unsigned x, unsigned y){
    transitions[x][y] = new char[100];
    strcpy(transitions[x][y], transition);
    return 0;
}

CState& CDeterminateFiniteAutomaton::getStateFromName(const char *name) const{
    for(unsigned i=0; i<numStates; i++){
        if(name==states[i]->getName()){
            return *states[i];
        }
    }
    CState *s = new CState();
    return *s;
}

 std::ostream& operator <<(std::ostream& out, CDeterminateFiniteAutomaton& rhs){
    rhs.extractor(out);
    return out;
}

std::ostream& CDeterminateFiniteAutomaton::extractor(std::ostream& out){
    out<<"\nAutomata configuration:\n";
    for(unsigned i=0; i<getNumStates(); i++){
        for(unsigned j=0; j<getNumSymbols(); j++){
            out<<transitions[i][j]<<"\t";
        }
        out<<std::endl<<std::endl;
    }
    for(unsigned i=0; i<getNumStates(); i++){
        out<<*states[i]<<std::endl;
    }
    return out;
}

bool CDeterminateFiniteAutomaton::testWord(const char *word) const{

    return false;
}
