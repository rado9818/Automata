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
        int setNumStates(unsigned);
        CState& getStateFromName(const char *) const;
        int initializeTransitions(unsigned);
        int addTransition(char*, unsigned, unsigned);
        virtual unsigned getNumSymbols() const = 0;
        virtual char* getAlphabetToChar() = 0;
        virtual CDeterminateFiniteAutomaton& operator=(const CDeterminateFiniteAutomaton& other);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomaton&);
        virtual std::istream& inserter(std::istream&);
        virtual std::istream& insertTransitions(std::istream&, CDeterminateFiniteAutomaton*);
    protected:
        CState **states;
    private:
        char ***transitions;
        unsigned numStates;
        unsigned numSymbols;
};

#endif // CDETERMINATEFINITEAUTOMATON_H
