#ifndef AUTOMATONSTATEEXCEPTION_H
#define AUTOMATONSTATEEXCEPTION_H

#include <iostream>
#include <exception>
#include <cstring>

class AutomatonStateException : public std::exception
{
    public:
        AutomatonStateException(char * = NULL, unsigned=0);
        virtual ~AutomatonStateException();
        AutomatonStateException(const AutomatonStateException& other);
        AutomatonStateException& operator=(const AutomatonStateException& other);
        char* getState();
        int setState(char* val);
        unsigned getLine();
        int setLine(unsigned);
        char* what();

    protected:

    private:
        char* state; //!< Member variable "state"
        unsigned line; //!< Member variable "line"
};

#endif // AUTOMATONSTATEEXCEPTION_H
