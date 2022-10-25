#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

int main()
{
    Node *dictionary = ReadFiles();

    PrintList(&dictionary);

    return 0;
}
