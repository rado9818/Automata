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

int CDeterminateFiniteAutomaton::setNumStates(unsigned numStates){
    this->numStates = numStates;
    return 0;
}

CState** CDeterminateFiniteAutomaton::setStates(CState** s, unsigned numStates){
    states = new CState*[numStates];
    for(unsigned i=0; i<numStates; i++){
        std::cout<<"setting states!!!\n";
        std::cout<<*s[i];

        states[i] = s[i];
    }
    return 0;
}

int CDeterminateFiniteAutomaton::addState(CState *s, unsigned pos){
    std::cout<<"~!!adding\n";
    std::cout<<*s<<std::endl;
    states[pos] = s;
    return 0;
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
    char **alphabet = rhs->getAlphabetToChar();
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
CState** CDeterminateFiniteAutomaton::getStates() const{
    return states;
}



 std::ostream& operator <<(std::ostream& out, CDeterminateFiniteAutomaton& rhs){
    rhs.extractor(out);
    return out;
}

std::ostream& CDeterminateFiniteAutomaton::extractor(std::ostream& out){
    out<<"\nAutomata configuration:\n";
    out<<std::setw(8)<<"   |";
    char **alphabet = getAlphabetToChar();
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

CDeterminateFiniteAutomaton* CDeterminateFiniteAutomaton::operator|(CDeterminateFiniteAutomaton& rhs){
    CDeterminateFiniteAutomaton *automataUnition = &rhs;

    char** alphabet1 = this->getAlphabetToChar();
    char** alphabet2 = rhs.getAlphabetToChar();

    CState** states1 = this->getStates();
    CState** states2 = rhs.getStates();


    unsigned numStates = this->getNumStates()*rhs.getNumStates();
    unsigned newNumSymbols = this->getNumSymbols()*rhs.getNumSymbols();


    char** newAlphabet = new char*[numSymbols];
    char***newTransitions = new char**[numStates];
    char***newTransitionsTable = new char**[numStates*newNumSymbols];
    for(int i=0; i<numStates; i++){
        newTransitionsTable[i] = new char*[newNumSymbols];
    }


    for(unsigned i=0; i<numStates; i++){
        newTransitions[i] = new char*[newNumSymbols];
    }

    unsigned letterPos = 0;
    CState** newStatesArr = new CState*[numStates*newNumSymbols];


    for(unsigned i=0; i<this->getNumSymbols(); i++){
        for(unsigned j=0; j<rhs.getNumSymbols(); j++){
            CState* stateToGo1;
            CState* stateToGo2;

            unsigned stateIdCnt = 1;
            unsigned stateAddingPos = 0;
            unsigned pos=0;
            unsigned transRow = 0;

            for(unsigned is=0; is<this->getNumStates(); is++){
                stateToGo1 = this->getNextState(is, i);

                for(unsigned isj=0; isj<rhs.getNumStates(); isj++){

                    stateToGo2 = rhs.getNextState(isj, j);

                    char *newState = new char[strlen(states[is]->getName()) + strlen(", ") + strlen(states[isj]->getName()) + 1];
                    strcpy(newState, states[is]->getName());
                    strcat(newState, ", ");
                    strcat(newState, states[isj]->getName());

                   // std::cout<<"state "<<states[is]->getName()<<" "<<states[isj]->getName()<<std::endl;

                    newStatesArr[stateAddingPos++] = new CState(stateIdCnt++, newState);

                    newTransitions[pos++][letterPos] = newState;

                    char *newTransition = new char[strlen(stateToGo1->getName()) + strlen(", ") + strlen(stateToGo2->getName()) + 1];
                    strcpy(newTransition, stateToGo1->getName());
                    strcat(newTransition, ", ");
                    strcat(newTransition, stateToGo2->getName());

                   // std::cout<<"trans "<<newTransition<<" addin at "<<transRow<<" "<<letterPos<<std::endl;
                    newTransitionsTable[transRow++][letterPos] = newTransition;

                }
            }


            char *newSybol = new char[strlen(alphabet1[i]) + strlen(", ") + strlen(alphabet2[j]) + 1];
            strcpy(newSybol, alphabet1[i]);
            strcat(newSybol, ", ");
            strcat(newSybol, alphabet2[j]);

            newAlphabet[letterPos] = newSybol;
       //     std::cout<<alphabet1[i]<<", "<<alphabet2[j]<<std::endl;
            letterPos++;

        }

    }


    automataUnition->setNumStates(numStates);
    automataUnition->setNumSymbols(newNumSymbols);

    automataUnition->setStates(newStatesArr, numStates);
    automataUnition->setAlphabet(newAlphabet, newNumSymbols);
    automataUnition->setTranstions(newTransitionsTable, numStates, newNumSymbols);
   /* for(unsigned i=0; i<this->getNumStates(); i++){
        for(unsigned j=0; j<rhs.getNumStates(); j++){
            std::cout<<states1[i]->getName()<<", "<<states2[j]->getName()<<std::endl;
        }

    }
*/
    return automataUnition;
}

CDeterminateFiniteAutomaton* CDeterminateFiniteAutomaton::operator^(CDeterminateFiniteAutomaton& rhs){
    CDeterminateFiniteAutomaton *automataAdditional = &rhs;
    for(unsigned i=0; i<automataAdditional->getNumStates(); i++){
        automataAdditional->states[i]->setIsFinal(!automataAdditional->states[i]->getIsFinal());
    }

    return automataAdditional;
}


int CDeterminateFiniteAutomaton::setTranstions(char*** transtions, unsigned numStates, unsigned numSymbols){

    this->numStates = numStates;
    this->numSymbols = numSymbols;

    this->transitions = new char**[numStates];
    for(unsigned i=0; i<numStates; i++){
        this->transitions[i] = new char*[numSymbols];
    }

    for(unsigned i=0; i<this->numStates; i++){
        for(unsigned j=0; j<this->numSymbols; j++){
            this->transitions[i][j] = new char[50];
        }
    }


    for(unsigned i=0; i<this->numStates; i++){
        for(unsigned j=0; j<this->numSymbols; j++){
            strcpy(this->transitions[i][j], transtions[i][j]);
        }
    }

    return 0;
}

