#include <iostream>
#include "structs.hpp"

using namespace std;

// Street Tree functions

Street new_street();
TreeNode* new_node(Street data);
void add_node(Street data, TreeNode **tree);
TreeNode search_node(int ID, TreeNode **tree);
TreeNode search_node(string street_name, TreeNode **tree);
void delete_node(int ID, TreeNode **tree);
void delete_node(string street_name, TreeNode **tree);
void print_street(Street data);
void print_street(int ID, TreeNode** tree);
void print_street(string name, TreeNode** tree);
void print_tree(TreeNode *root, int counter);
void print_tree(TreeNode *root);

// House list functions

House new_house();
HouseNode* new_house_node(House data);
void add_house(HouseNode* node, HouseNode **list);
void remove_all_houses(HouseNode **list);
void remove_house(string number, HouseNode **list);
int list_size(HouseNode *list);
void print_house(House data);
void print_list (HouseNode* list); 

// File Stream functions

void save_all(TreeNode **tree);
TreeNode *read_files();
void clear_files();