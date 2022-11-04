#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

int main () {
    Street pirineos = new_street();
    Street pirineos2 = new_street();
    Street pirineos3 = new_street();
    Street pirineos4 = pirineos;

    TreeNode* RootNode = NULL;
    
    add_node(pirineos, &RootNode);
    add_node(pirineos2, &RootNode);
    add_node(pirineos3, &RootNode);
    add_node(pirineos4, &RootNode);

    print_tree(RootNode);

}