#ifndef CDETERMINATEFINITEAUTOMATONINT_H
#define CDETERMINATEFINITEAUTOMATONINT_H
#include "CDeterminateFiniteAutomaton.h"
#include <iostream>
class CDeterminateFiniteAutomatonInt : public CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomatonInt();
        virtual ~CDeterminateFiniteAutomatonInt();
        CDeterminateFiniteAutomatonInt(const CDeterminateFiniteAutomatonInt& other);
        CDeterminateFiniteAutomatonInt& operator=(const CDeterminateFiniteAutomatonInt& other);
        const int* getAlphabet() const;
        int setAlphabet(int*);
        unsigned getNumSymbols() const;
        virtual char* getAlphabetToChar();
        int setNumSymbols(unsigned);
        virtual std::istream& inserter(std::istream&);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomatonInt&);
        bool testWord(char *) const;
        unsigned getLetterPosition(int) const;
    protected:
    private:
        unsigned numSymbols;
        int *alphabet;
};

#endif // CDETERMINATEFINITEAUTOMATONINT_H
