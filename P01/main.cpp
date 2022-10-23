#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

int main()
{
    Node *dictionary = NULL;
    Word p_word1 = {"1","","",""};
    Word p_word2 = {"2","","",""};
    Word p_word3 = {"3","","",""};
    Word p_word4 = {"4","","",""};
    Word p_word5 = {"5","","",""};
    Word p_word6 = {"6","","",""};
    Word p_word7 = {"7","","",""};
    Word p_word8 = {"8","","",""};
    Word p_word9 = {"9","","",""};

    AddAtEnd(p_word1, &dictionary);
    AddAtStart(p_word2, &dictionary);
    AddAtEnd(p_word3, &dictionary);
    AddAtStart(p_word4, &dictionary);
    AddAtEnd(p_word5, &dictionary);

    PrintList(&dictionary);

    RemoveAtStart(&dictionary);
    RemoveAtStart(&dictionary);
    RemoveAtEnd(&dictionary);
    RemoveAtEnd(&dictionary);

    PrintList(&dictionary);

    AddAtEnd(p_word6, &dictionary);
    AddAtEnd(p_word7, &dictionary);
    AddBefore(p_word8, &dictionary,"1");
    AddAfter(p_word9, &dictionary,"7");

    PrintList(&dictionary);

    return 0;
}
