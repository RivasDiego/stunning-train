#include <iostream>

using namespace std;

struct street{
    string ID;
    string name;
    bool is_private;
    int hosues;
};
typedef struct street Street;
typedef Street T;

struct tree_node{

    struct tree_node* left_child;
    struct tree_node* right_child;
};
typedef struct tree_node Node;