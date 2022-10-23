#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

int main()
{
    Node *dictionary = NULL;
    Word p_word1 = {"Uno","","",""};
    Word p_word2 = {"Dos","","",""};
    Word p_word3 = {"Tres","","",""};
    Word p_word4 = {"Cuatro","","",""};
    Word p_word5 = {"Cinco","","",""};
    Word p_word6 = {"Seis","","",""};
    Word p_word7 = {"Siete","","",""};
    Word p_word8 = {"Ocho","","",""};
    Word p_word9 = {"Nueve","","",""};

    AddAtEnd(p_word1, &dictionary);
    AddAtStart(p_word2, &dictionary);
    AddAtEnd(p_word3, &dictionary);
    AddAtStart(p_word4, &dictionary);
    AddAtEnd(p_word5, &dictionary);

    // PrintList(&dictionary);

    RemoveAtStart(&dictionary);
    RemoveAtStart(&dictionary);
    RemoveAtEnd(&dictionary);
    RemoveAtEnd(&dictionary);

    // PrintList(&dictionary);

    AddAtEnd(p_word6, &dictionary);
    AddAtEnd(p_word7, &dictionary);
    AddBefore(p_word8, &dictionary,"seis");
    AddAfter(p_word9, &dictionary,"siEtE");

    // PrintList(&dictionary);
    PrintList(&dictionary);

    RemoveWord(&dictionary, "seis");

    PrintList(&dictionary);
    
    return 0;
}
