#ifndef CDETERMINATEFINITEAUTOMATON_H
#define CDETERMINATEFINITEAUTOMATON_H
#include<iostream>
#include "CState.h"
class CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomaton();
        virtual ~CDeterminateFiniteAutomaton();
        CDeterminateFiniteAutomaton(const CDeterminateFiniteAutomaton& other);
        unsigned getNumStates() const;
        virtual CDeterminateFiniteAutomaton& operator=(const CDeterminateFiniteAutomaton& other);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomaton&);
        virtual std::istream& inserter(std::istream&);
    protected:
        char ***transitions;
        CState **states;
    private:
        unsigned numStates;
};

#endif // CDETERMINATEFINITEAUTOMATON_H
