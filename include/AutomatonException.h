#ifndef AUTOMATONEXCEPTION_H
#define AUTOMATONEXCEPTION_H

#include <iostream>
#include <exception>
#include <cstring>
#include "AutomatonException.h"

class AutomatonException : public std::exception
{
    public:
        AutomatonException(char * = NULL, unsigned=0);
        virtual ~AutomatonException();
        AutomatonException(const AutomatonException&);
        AutomatonException& operator=(const AutomatonException&);
        unsigned getLine() const;
        int setLine(unsigned);
        char* getState();
        int setState(char*);
        char* what();
    protected:

    private:
        unsigned line;
        char* state;
};

#endif // AUTOMATONEXCEPTION_H
