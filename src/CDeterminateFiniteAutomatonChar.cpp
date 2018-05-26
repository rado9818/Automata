#include "CDeterminateFiniteAutomatonChar.h"

CDeterminateFiniteAutomatonChar::CDeterminateFiniteAutomatonChar()
{
    //ctor
}

CDeterminateFiniteAutomatonChar::~CDeterminateFiniteAutomatonChar()
{
    //dtor
    if(alphabet!=NULL){
        delete[] alphabet;
    }
}

CDeterminateFiniteAutomatonChar::CDeterminateFiniteAutomatonChar(const CDeterminateFiniteAutomatonChar& other)
{
    //copy ctor
}

CDeterminateFiniteAutomatonChar& CDeterminateFiniteAutomatonChar::operator=(const CDeterminateFiniteAutomatonChar& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::istream& CDeterminateFiniteAutomatonChar::inserter(std::istream& in){
    CDeterminateFiniteAutomaton::inserter(in);

    //enter the alphabet
    std::cout<<"Enter the number of symbols in the alphabet\n";
    in>>numSymbols;
    alphabet = new char[numSymbols];
    for(unsigned i=0; i<numSymbols; i++){
        std::cout<<"Enter the "<<i+1<<" letter: ";
        in>>alphabet[i];
    }

    //enter the transitions
    CDeterminateFiniteAutomaton::initializeTransitions(numSymbols);
    CDeterminateFiniteAutomaton::insertTransitions(in, this);

    return in;

}

unsigned CDeterminateFiniteAutomatonChar::getNumSymbols() const{
    return numSymbols;
}

const char* CDeterminateFiniteAutomatonChar::getAlphabet() const{
    return alphabet;
}

char* CDeterminateFiniteAutomatonChar::getAlphabetToChar(){
    return alphabet;
}

 std::istream& operator >>(std::istream& in, CDeterminateFiniteAutomatonChar& rhs){
    rhs.inserter(in);
    return in;
}
