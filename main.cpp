#include <iostream>
#include "CDeterminateFiniteAutomaton.h"
#include "CDeterminateFiniteAutomatonInt.h"
#include "CDeterminateFiniteAutomatonChar.h"
#define AUTOMATA_INT 1
#define AUTOMATA_CHAR 2
using namespace std;

int main()
{
    CDeterminateFiniteAutomaton *automata = NULL;
    unsigned short automataType;

    do{
        cout<<"Select you alphabet type:\n\t1 - Numbers\n\t2 - Chars\n";
        cin>>automataType;
        if(automataType==AUTOMATA_INT){
            automata = new CDeterminateFiniteAutomatonInt();
        }else if(automataType==AUTOMATA_CHAR){
            automata = new CDeterminateFiniteAutomatonChar();
        }
    }while(automataType!=AUTOMATA_INT && automataType!=AUTOMATA_CHAR);

    cin>>*automata;

    return 0;
}
