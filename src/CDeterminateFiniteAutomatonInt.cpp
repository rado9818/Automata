#include "CDeterminateFiniteAutomatonInt.h"

CDeterminateFiniteAutomatonInt::CDeterminateFiniteAutomatonInt()
{
    //ctor
}

CDeterminateFiniteAutomatonInt::~CDeterminateFiniteAutomatonInt()
{
    //dtor
    if(alphabet!=NULL){
        delete[] alphabet;
    }
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
unsigned CDeterminateFiniteAutomatonInt::getNumSymbols() const{
    return numSymbols;
}

const int* CDeterminateFiniteAutomatonInt::getAlphabet() const{
    return alphabet;
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
    CDeterminateFiniteAutomaton::initializeTransitions(numSymbols);
    CDeterminateFiniteAutomaton::insertTransitions(in, this);

    return in;

}

char* CDeterminateFiniteAutomatonInt::getAlphabetToChar(){
    char *newAlphabet = new char[numSymbols];
    for(unsigned i=0; i<numSymbols; i++){
        newAlphabet[i] = alphabet[i]+'0';
    }

    return newAlphabet;
}


 std::istream& operator >>(std::istream& in, CDeterminateFiniteAutomatonInt& rhs){
    rhs.inserter(in);
    return in;
}

bool CDeterminateFiniteAutomatonInt::testWord(char *word) const{
    CState *s = getInitialState();
    char *p = word;
    while(*p!='\0'){
        unsigned letterPosition = getLetterPosition(*p-'0');
        if(letterPosition != -1){
            s = CDeterminateFiniteAutomaton::getNextState(s->getId(), letterPosition);
          //  std::cout<<s->getName()<<std::endl;
        }
        p++;
    }

    return s->getIsFinal();
}

unsigned CDeterminateFiniteAutomatonInt::getLetterPosition(int symbolNeeded) const{
    for(unsigned i=0; i<getNumSymbols(); i++){
        if(alphabet[i]==symbolNeeded){
            return i;
        }
    }
    return -1;
}
