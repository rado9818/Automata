#ifndef CDETERMINATEFINITEAUTOMATONCHAR_H
#define CDETERMINATEFINITEAUTOMATONCHAR_H
#include "CDeterminateFiniteAutomaton.h"


class CDeterminateFiniteAutomatonChar : public CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomatonChar();
        virtual ~CDeterminateFiniteAutomatonChar();
        CDeterminateFiniteAutomatonChar(const CDeterminateFiniteAutomatonChar& other);
        CDeterminateFiniteAutomatonChar& operator=(const CDeterminateFiniteAutomatonChar& other);
        char* getAlphabet() const;
        int setAlphabet(char* val);
    protected:
    private:
        char* alphabet;
};

#endif // CDETERMINATEFINITEAUTOMATONCHAR_H
