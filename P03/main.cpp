#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

int main () {

    TreeNode* RootNode = NULL;

    add_node({4, "A", true}, &RootNode);
    add_node({2, "B", true}, &RootNode);
    add_node({6, "C", true}, &RootNode);
    add_node({7, "D", true}, &RootNode);
    add_node({5, "E", true}, &RootNode);
    add_node({3, "F", true}, &RootNode);
    add_node({1, "G", true}, &RootNode);

    TreeNode* test_node = search_node(1, RootNode);
    print_street(test_node->element);
    test_node = search_node(2, RootNode);
    print_street(test_node->element);
    test_node = search_node(3, RootNode);
    print_street(test_node->element);
    test_node = search_node(4, RootNode);
    print_street(test_node->element);
    test_node = search_node(5, RootNode);
    print_street(test_node->element);
    test_node = search_node(6, RootNode);
    print_street(test_node->element);
    test_node = search_node(7, RootNode);
    print_street(test_node->element);
    
    print_tree(RootNode);

}