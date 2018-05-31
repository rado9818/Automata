#include "AutomatonStateException.h"

AutomatonStateException::AutomatonStateException(char *state, unsigned line):
    state(new char[strlen(state)+1]), line(line)
{
    //ctor
    strcpy(this->state, state);
}

AutomatonStateException::~AutomatonStateException()
{
    //dtor
    if(state!=NULL){
        delete[] state;
    }
}

AutomatonStateException::AutomatonStateException(const AutomatonStateException& other)
{
    //copy ctor
}

AutomatonStateException& AutomatonStateException::operator=(const AutomatonStateException& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

char* AutomatonStateException::what(){
    char* exceptionText = new char[
        strlen("State ") + strlen(state)+
        strlen(" not found at line ")+
        strlen(std::to_string(line).c_str()) + 1
    ];
    strcpy(exceptionText, "State ");
    strcat(exceptionText, state);
    strcat(exceptionText, " not found at line ");
    strcat(exceptionText, std::to_string(line).c_str());
    return exceptionText;
}
