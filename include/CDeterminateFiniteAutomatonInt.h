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
        int* getAlphabet() const;
        int setAlphabet(int*);
        unsigned getNumSymbols() const;
        int setNumSymbols(unsigned);
        virtual std::istream& inserter(std::istream&);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomatonInt&);

    protected:
    private:
        unsigned numSymbols;
        int *alphabet;
};

#endif // CDETERMINATEFINITEAUTOMATONINT_H
