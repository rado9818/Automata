#ifndef CDETERMINATEFINITEAUTOMATON_H
#define CDETERMINATEFINITEAUTOMATON_H


class CDeterminateFiniteAutomaton
{
    public:
        CDeterminateFiniteAutomaton();
        virtual ~CDeterminateFiniteAutomaton();
        CDeterminateFiniteAutomaton(const CDeterminateFiniteAutomaton& other);
        virtual CDeterminateFiniteAutomaton& operator=(const CDeterminateFiniteAutomaton& other) = 0;
    protected:
    private:
        unsigned numStates;
};

#endif // CDETERMINATEFINITEAUTOMATON_H
