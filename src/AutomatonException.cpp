#include "AutomatonException.h"

AutomatonException::AutomatonException(char *state, unsigned line):
    state(new char[strlen(state)]), line(line)
{
    //ctor
    strcpy(this->state, state);
}

AutomatonException::~AutomatonException()
{
    //dtor
    if(state!=NULL){
        delete[] state;
    }
}

AutomatonException::AutomatonException(const AutomatonException& other)
{
    //copy ctor
}

AutomatonException& AutomatonException::operator=(const AutomatonException& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

char* AutomatonException::what(){
    char* exceptionText = new char[strlen("The state ")+strlen(state)
    + strlen(" has already been marked at initial and you cannot have >1 initial states. ")
    + strlen("The line which causes the exception is ") + strlen(std::to_string(line).c_str())
    + strlen("\n") +
    1];
    strcpy(exceptionText, "The state ");
    strcat(exceptionText, state);
    strcat(exceptionText, " has already been marked at initial and you cannot have >1 initial states. ");
    strcat(exceptionText, "The line which causes the exception is ");
    strcat(exceptionText, std::to_string(line).c_str());
    strcat(exceptionText, "\n");
    return exceptionText;
}
