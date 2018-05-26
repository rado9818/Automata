#include <iostream>
#include <fstream>
#include "CDeterminateFiniteAutomaton.h"
#include "CDeterminateFiniteAutomatonInt.h"
#include "CDeterminateFiniteAutomatonChar.h"
#define AUTOMATA_INT 1
#define AUTOMATA_CHAR 2
#define READ_FROM_CONSOLE 1
using namespace std;

int main()
{
    CDeterminateFiniteAutomaton *automata = NULL;
    int automataType;
    std::istream *stream = &cin;
    int readFrom;
    cout<<"Choose the input type:\n\t1 - Console\n\t2/or any number != 1/ - File\n";
    cin>>readFrom;
    if(readFrom!=READ_FROM_CONSOLE){
        cin.ignore();
        cin.clear();
        ifstream file("file.txt");
        stream = &file;
    }
    do{
        cout<<"Select you alphabet type:\n\t1 - Numbers\n\t2 - Chars\n";
        *stream>>automataType;
        if(automataType==AUTOMATA_INT){
            automata = new CDeterminateFiniteAutomatonInt();
        }else if(automataType==AUTOMATA_CHAR){
            automata = new CDeterminateFiniteAutomatonChar();
        }
    }while(automataType!=AUTOMATA_INT && automataType!=AUTOMATA_CHAR);

    *stream>>*automata;

    return 0;
}
