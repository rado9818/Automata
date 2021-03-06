#ifndef CDETERMINATEFINITEAUTOMATON_H
#define CDETERMINATEFINITEAUTOMATON_H
#include<iostream>
#include<iomanip>
#include<typeinfo>
#include "CState.h"
#include "AutomatonStateException.h"

class CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomaton();
        virtual ~CDeterminateFiniteAutomaton();
        CDeterminateFiniteAutomaton(const CDeterminateFiniteAutomaton&);
        unsigned getNumStates() const;
        int setNumStates(unsigned);
        virtual int setNumSymbols(unsigned) = 0;
        CState** setStates(CState**, unsigned);
        CState** getStates() const;
        virtual int setAlphabet(char**, unsigned) = 0;
        int addState(CState *, unsigned);
        CState* getStateFromName(char *) const;
        CState* getInitialState() const;
        int initializeTransitions(unsigned);
        int addTransition(char*, unsigned, unsigned);
        int setTranstions(char***, unsigned, unsigned);
        virtual unsigned getNumSymbols() const = 0;
        virtual char** getAlphabetToChar() = 0;
        virtual CDeterminateFiniteAutomaton& operator=(const CDeterminateFiniteAutomaton& other);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomaton&);
        friend std::ostream& operator <<(std::ostream&, CDeterminateFiniteAutomaton&);
        virtual std::istream& inserter(std::istream&);
        virtual std::ostream& extractor(std::ostream&);
        virtual std::istream& insertTransitions(std::istream&, CDeterminateFiniteAutomaton*);
        CState* getNextState(unsigned, unsigned) const;
        virtual bool testWord(char *) const = 0;
        CDeterminateFiniteAutomaton* operator&(CDeterminateFiniteAutomaton&);
        CDeterminateFiniteAutomaton* operator|(CDeterminateFiniteAutomaton&);
        CDeterminateFiniteAutomaton* operator^(CDeterminateFiniteAutomaton&);
    protected:
        CState **states;
    private:
        char ***transitions;
        unsigned numStates;
        unsigned numSymbols;
};

#endif // CDETERMINATEFINITEAUTOMATON_H
