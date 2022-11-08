#include <iostream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

int main () {

    Node* RootNode = NULL;

    add_node({8, "A", true}, &RootNode);
    add_node({7, "K", true}, &RootNode);
    add_node({6, "E", true}, &RootNode);
    add_node({5, "J", true}, &RootNode);
    add_node({4, "B", true}, &RootNode);
    add_node({3, "I", true}, &RootNode);
    
    add_node({12, "C", true}, &RootNode);
    add_node({2, "D", true}, &RootNode);
    // add_node({10, "F", true}, &RootNode);
    add_node({14, "G", true}, &RootNode);
    // add_node({1, "H", true}, &RootNode);
    // add_node({9, "L", true}, &RootNode);
    // add_node({11, "M", true}, &RootNode);
    // add_node({13, "N", true}, &RootNode);
    add_node({15, "O", true}, &RootNode);
    add_node({16, "O", true}, &RootNode);
    add_node({17, "O", true}, &RootNode);
    add_node({18, "O", true}, &RootNode);

    Node* test_node = search_node(1, RootNode);
    print_street(test_node->element);

    test_node = search_parent_node(1, RootNode);
    print_street(test_node->element);
    
    print_tree(RootNode);
    int n = 6;
    test_node = search_node(n, RootNode);
    Node* parent_node = search_parent_node(n, RootNode);
    delete_node(&test_node, &parent_node);
    n = 5;
    test_node = search_node(n, RootNode);
    Node* parent_node = search_parent_node(n, RootNode);
    delete_node(&test_node, &parent_node);
    n = 3;
    test_node = search_node(n, RootNode);
    Node* parent_node = search_parent_node(n, RootNode);
    delete_node(&test_node, &parent_node);

    print_tree(RootNode);

}