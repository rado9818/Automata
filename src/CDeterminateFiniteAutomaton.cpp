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
        states[i] = new CState(i);
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
    transitions = new char**[30];
    for(unsigned i=0; i<30; i++){
        transitions[i] = new char*[30];
        for(unsigned j=0; j<30; j++){
            transitions[i][j] = new char [100];
        }
    }
    return 0;
}

std::istream& CDeterminateFiniteAutomaton::insertTransitions(std::istream& in, CDeterminateFiniteAutomaton* rhs){
    in.ignore();
    char *alphabet = rhs->getAlphabetToChar();
    for(unsigned i=0; i<getNumStates(); i++){
        for(unsigned j=0; j<rhs->getNumSymbols(); j++){
            std::cout<<"Enter ("<<states[i]->getName()<<", "<<alphabet[j]<<"): ";
            char *transition = new char[50];
            in.getline(transition, 49);
            //std::cout<<"adding "<<transition<<" at "<<i << "  "<<j<<std::endl;
            addTransition(transition, i, j);
        }
    }
    std::cout<<"Enter initial state\n";
    char *transition = new char[50];
    in.getline(transition, 49);

    CState *s = getStateFromName(transition);
    try{
        s->setIsInitial(true, states, numStates, __LINE__);
    }
    catch(AutomatonException &e){
        std::cerr<<typeid(e).name()<<": "<<e.what()<<std::endl;
    }

    if(transition!=NULL){
        if(transition != NULL){
            delete[] transition;
        }
    }

    std::cout<<"Enter the number of final states\n";
    unsigned numFinalStates;
    in>>numFinalStates;
    in.ignore();
    in.clear();
    for(unsigned i=0; i<numFinalStates; i++){
        std::cout<<"Enter the "<<i+1<<" final state"<<std::endl;
        char *finalState = new char[50];

        bool isStateFound = true;
        while(isStateFound){
            memset(finalState, sizeof(finalState), '\0');
            in.getline(finalState, 49);
            try{
                CState *s1 = getStateFromName(finalState);
                s1->setIsFinal(true);
                isStateFound = false;
            }
            catch(AutomatonStateException &e){
                std::cerr<<typeid(e).name()<<": "<<e.what()<<std::endl;
            }
        }
        if(finalState!=NULL){
            delete[] finalState;
        }
    }
    return in;
}
int CDeterminateFiniteAutomaton::addTransition(char* transition, unsigned x, unsigned y){
    strcpy(transitions[x][y], transition);
    return 0;
}

CState* CDeterminateFiniteAutomaton::getStateFromName(char *name) const{
    char *newChar = new char[strlen(name)];
    char *p = name;
    unsigned cnt=0;
    while(*p!='\0'){
        newChar[cnt++] = *p;
        p++;
    }
    newChar[cnt] = '\0';


    for(unsigned i=0; i<numStates; i++){
        //strcmp returns 0 if the c strings match
        if(strcmp(newChar, states[i]->getName())==0){
            return states[i];
        }
    }
    throw AutomatonStateException(newChar, __LINE__);

    CState *s = new CState(0);
    return s;
}

CState* CDeterminateFiniteAutomaton::getInitialState() const{
    for(unsigned i=0; i<numStates; i++){
        if(states[i]->getIsInitial()){
            return states[i];
        }
    }
    CState *s = new CState(0);
    return s;
}


 std::ostream& operator <<(std::ostream& out, CDeterminateFiniteAutomaton& rhs){
    rhs.extractor(out);
    return out;
}

std::ostream& CDeterminateFiniteAutomaton::extractor(std::ostream& out){
    out<<"\nAutomata configuration:\n";
    out<<std::setw(8)<<"   |";
    char *alphabet = getAlphabetToChar();
    for(unsigned i=0; i<getNumSymbols(); i++){
        out<<std::setw(6)<<alphabet[i]<<"\t";
    }
    out<<std::endl;
    for(unsigned i=0; i<6*(getNumSymbols()+2); i++){
        out<<"-";
    }
    out<<std::endl;

    for(unsigned i=0; i<getNumStates(); i++){
        out<<std::setw(6)<<states[i]->getName()<<" | ";
        for(unsigned j=0; j<getNumSymbols(); j++){
            out<<std::setw(6)<<transitions[i][j]<<"\t";
        }
        out<<std::endl<<std::endl;
    }
    for(unsigned i=0; i<getNumStates(); i++){
        out<<*states[i]<<std::endl;
    }
    return out;
}

CState* CDeterminateFiniteAutomaton::getNextState(unsigned stateId, unsigned letterPos) const{
    return getStateFromName( transitions[stateId][letterPos]);
}
