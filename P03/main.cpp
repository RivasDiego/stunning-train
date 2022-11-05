#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

int main () {

    TreeNode* RootNode = NULL;
    Street pirineos0 = {4, "A", true};
    Street pirineos1 = {2, "B", true};
    Street pirineos2 = {6, "C", true};
    Street pirineos3 = {7, "D", true};
    Street pirineos4 = {5, "E", true};
    Street pirineos5 = {3, "F", true};
    Street pirineos6 = {1, "G", true};

    add_node(pirineos0, &RootNode);
    add_node(pirineos1, &RootNode);
    add_node(pirineos2, &RootNode);
    add_node(pirineos6, &RootNode);
    add_node(pirineos3, &RootNode);
    add_node(pirineos4, &RootNode);
    add_node(pirineos5, &RootNode);

    TreeNode* test_node = search_node(1, &RootNode);
    print_street(test_node->element);
    test_node = search_node(2, &RootNode);
    print_street(test_node->element);
    test_node = search_node(3, &RootNode);
    print_street(test_node->element);
    test_node = search_node(4, &RootNode);
    print_street(test_node->element);
    test_node = search_node(5, &RootNode);
    print_street(test_node->element);
    test_node = search_node(6, &RootNode);
    print_street(test_node->element);
    test_node = search_node(7, &RootNode);
    print_street(test_node->element);
    test_node = search_node(8, &RootNode);
    print_street(test_node->element);
    
    print_tree(RootNode);

}