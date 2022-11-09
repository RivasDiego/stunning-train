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
    add_node({4, "B", true}, &RootNode);
    add_node({12, "C", true}, &RootNode);
    add_node({2, "D", true}, &RootNode);
    add_node({6, "E", true}, &RootNode);
    add_node({10, "F", true}, &RootNode);
    add_node({14, "G", true}, &RootNode);
    add_node({1, "H", true}, &RootNode);
    add_node({3, "I", true}, &RootNode);
    add_node({5, "J", true}, &RootNode);
    add_node({7, "K", true}, &RootNode);
    add_node({9, "L", true}, &RootNode);
    add_node({11, "M", true}, &RootNode);
    add_node({13, "N", true}, &RootNode);
    add_node({15, "O", true}, &RootNode);

    Node* test_node = search_node(1, RootNode);
    print_street(test_node->element);

    add_house({"507", "Green", 2}, &(test_node->element.hosues));
    add_house({"88A", "Yellow", 5}, &(test_node->element.hosues));
    add_house({"951", "Black", 7}, &(test_node->element.hosues));
    add_house({"234", "Blue", 1}, &(test_node->element.hosues));
    add_house({"1-A", "Red", 3}, &(test_node->element.hosues));

    print_list(test_node->element.hosues);

    print_house("1-A", test_node->element.hosues);
    remove_house(&(test_node->element.hosues), "234");
    
    print_list(test_node->element.hosues);

    print_tree(RootNode);

}