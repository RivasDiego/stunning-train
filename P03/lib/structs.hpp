#include <iostream>

using namespace std;

struct house{
    string number;
    string color;
    int people;
};
typedef struct house House;

struct house_node{
    House element;
    House* next;
};
typedef struct house_node HouseNode;

const House INVALID_HOUSE = {"INVALID_DATA","",-1};

struct street{
    int ID;
    string name;
    bool is_private;
    HouseNode* hosues = NULL;
};
typedef struct street Street;

struct tree_node{
    Street element;
    struct tree_node* left_child = NULL;
    struct tree_node* right_child = NULL;
};
typedef struct tree_node TreeNode;

const Street INVALID_STREET = {-1, "INVALID_DATA", NULL}; 