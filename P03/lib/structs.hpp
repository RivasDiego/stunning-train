#include <iostream>

using namespace std;

struct house{
    string number;
    string color;
    int people;
};
typedef struct house House;

struct street{
    string ID;
    string name;
    bool is_private;
    House* hosues = NULL;
};

typedef struct street Street;
typedef Street T;

struct tree_node{
    Street element;
    struct tree_node* left_child = NULL;
    struct tree_node* right_child = NULL;
};
typedef struct tree_node TreeNode;