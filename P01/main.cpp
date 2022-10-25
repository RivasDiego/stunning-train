#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

int main()
{
    Node *dictionary = ReadFiles();

/*     PrintList(&dictionary);

    char op;
    cin >> op;

    if(op == 'n')
        return 0;
    AddAtEnd(p_word1, &dictionary);
    AddAtStart(p_word2, &dictionary);
    AddAtEnd(p_word3, &dictionary);
    AddAtStart(p_word4, &dictionary);
    AddAtEnd(p_word5, &dictionary); */


    PrintList(&dictionary);
    
    return 0;
}
