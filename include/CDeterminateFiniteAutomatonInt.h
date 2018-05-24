#ifndef CDETERMINATEFINITEAUTOMATONINT_H
#define CDETERMINATEFINITEAUTOMATONINT_H
#include "CDeterminateFiniteAutomaton.h"

class CDeterminateFiniteAutomatonInt : public CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomatonInt();
        virtual ~CDeterminateFiniteAutomatonInt();
        CDeterminateFiniteAutomatonInt(const CDeterminateFiniteAutomatonInt& other);
        CDeterminateFiniteAutomatonInt& operator=(const CDeterminateFiniteAutomatonInt& other);
        int* getAlphabet() const;
        int* setAlphabet(int* val);
    protected:
    private:
        int *alphabet;
};

#endif // CDETERMINATEFINITEAUTOMATONINT_H
