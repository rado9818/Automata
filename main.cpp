#include <iostream>
#include <cstring>
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
    CDeterminateFiniteAutomaton *newAutomata = NULL;

    int automataType;
    std::istream *stream = &cin;
    int readFrom;
    cout<<"Choose the input type:\n\t1 - Console\n\t2/or any number != 1/ - File\n";
    cin>>readFrom;

    if(readFrom!=READ_FROM_CONSOLE){
        cin.ignore();
        cin.clear();
        ifstream *file = new ifstream("C:\\Users\\rados\\Desktop\\Automata\\Automata\\file.txt");
        stream = file;
    }

    do{
        cout<<"Select you alphabet type:\n\t1 - Numbers\n\t2 - Chars\n";
        *stream>>automataType;
        if(automataType==AUTOMATA_INT){
            automata = new CDeterminateFiniteAutomatonInt();
            newAutomata = new CDeterminateFiniteAutomatonChar();
        }else if(automataType==AUTOMATA_CHAR){
            automata = new CDeterminateFiniteAutomatonChar();
            newAutomata = new CDeterminateFiniteAutomatonChar();
        }
    }while(automataType!=AUTOMATA_INT && automataType!=AUTOMATA_CHAR);

    *stream>>*automata;
    stream = new ifstream("C:\\Users\\rados\\Desktop\\Automata\\Automata\\file.txt");
    int tst;
    *stream>>tst;
    *stream>>*newAutomata;

    cout<<*automata;

    cout<<"\n\n\nhere is a new automata: \n";
    CDeterminateFiniteAutomaton *automataUnition = *automata|*newAutomata;
    cout<<*automataUnition<<endl;

    char word[100];
    do{
        cout<<"Enter a word in the automata. Type \"end\" to exit\n";
        cin.getline(word, 99);
        if(strcmp(word, "end")==0){
            break;
        }
        cout<<"The word \""<<word<<"\" is "<<(automata->testWord(word) ? "":"NOT ")<<"recognized!"<<endl;
    }while(strcmp(word, "end")!=0);
    return 0;
}
