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

int CDeterminateFiniteAutomatonChar::setAlphabet(char** alphabet, unsigned numSymbols){
    this->alphabet = new char*[numSymbols];
    for(unsigned i=0; i<numSymbols; i++){
        this->alphabet[i] = new char[50];
        strcpy(this->alphabet[i], alphabet[i]);
    }
    return 0;
}
/*
int CDeterminateFiniteAutomatonChar::setNumSymbols(unsigned numSymbols){
    this->numSymbols = numSymbols;
    return 0;
}*/

int CDeterminateFiniteAutomatonChar::setNumSymbols(unsigned numSymbols){
    this->numSymbols = numSymbols;
    return 0;
}


std::istream& CDeterminateFiniteAutomatonChar::inserter(std::istream& in){
    CDeterminateFiniteAutomaton::inserter(in);

    //enter the alphabet
    std::cout<<"Enter the number of symbols in the alphabet\n";
    in>>numSymbols;
    alphabet = new char*[numSymbols];
    for(unsigned i=0; i<numSymbols; i++){
        alphabet[i] = new char[50];
    }

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

char** CDeterminateFiniteAutomatonChar::getAlphabet() const{
    return alphabet;
}

char** CDeterminateFiniteAutomatonChar::getAlphabetToChar(){
    return alphabet;
}

 std::istream& operator >>(std::istream& in, CDeterminateFiniteAutomatonChar& rhs){
    rhs.inserter(in);
    return in;
}

bool CDeterminateFiniteAutomatonChar::testWord(char *word) const{
    CState *s = getInitialState();
    char *p = word;
    while(*p!='\0'){
        unsigned letterPosition = getLetterPosition(p);
        if(letterPosition != -1){
            s = CDeterminateFiniteAutomaton::getNextState(s->getId(), letterPosition);
          //  std::cout<<s->getName()<<std::endl;
        }
        p++;
    }

    return s->getIsFinal();
}


unsigned CDeterminateFiniteAutomatonChar::getLetterPosition(char* symbolNeeded) const{
    for(unsigned i=0; i<getNumSymbols(); i++){
        if(alphabet[i]==symbolNeeded){
            return i;
        }
    }
    return -1;
}
