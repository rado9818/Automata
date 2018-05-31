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
        char** getAlphabet() const;
        int setAlphabet(char* val);
        char** getAlphabetToChar();
        unsigned getNumSymbols() const;
        virtual std::istream& inserter(std::istream&);
        friend std::istream& operator >>(std::istream&, CDeterminateFiniteAutomatonChar&);
        bool testWord(char *) const;
        unsigned getLetterPosition(char *) const;

    protected:
    private:
        unsigned numSymbols;
        char** alphabet;
};

#endif // CDETERMINATEFINITEAUTOMATONCHAR_H
