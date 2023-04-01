#include <iostream>
#include "structs.hpp"

using namespace std;

// Tree functions

Node* new_node(Street data);
void add_node(Street data, Node **tree);
void print_tree(Node *root, int counter);
void print_tree(Node *root);
Node *search_node(int ID, Node *tree);
Node *search_parent_node_helper(int ID, Node *current_node, Node *parent);
Node *search_parent_node(int ID, Node *tree);
Node *search_min_node(Node *tree);
void swap_nodes(Node** old_node, Node** new_node);
void delete_node(Node** node_to_delete, Node** parent_of_node_to_delete);
bool is_leaf(Node* node);
bool has_only_left(Node* node);
bool has_only_right(Node* node);
bool has_both(Node* node);
bool is_root(Node* node, Node* parent);
bool is_tree_empty(Node *root);
void inorder_traversal(Node* tree);
void preorder_traversal(Node* tree);
void postorder_traversal(Node* tree);

// Street functions

Street new_street();
void print_street(Street data);
void print_street(int ID, Node *tree);
bool street_exist(int ID, Node *tree);

// House functions

House new_house();
void print_house( House house);
void print_house(string number, HouseNode* list);

// List functions

HouseNode* new_house_node(House element);
void add_house(House data, HouseNode **list);
bool list_empty(HouseNode *list);
HouseNode* find_house_node(HouseNode *list, string house_number);
void print_list(HouseNode *list);
void remove_house(HouseNode **list, string word);

// File functions