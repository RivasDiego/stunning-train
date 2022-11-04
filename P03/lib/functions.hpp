#include <iostream>
#include "structs.hpp"

using namespace std;

// Tree functions

Street new_street() {}
TreeNode new_node(Street data) {}
void add_node(TreeNode node, TreeNode **tree) {}
void search_node_by_id(int ID, TreeNode **tree) {}
void search_node_by_name(string street_name, TreeNode **tree) {}
void delete_node_by_id(int ID, TreeNode **tree) {}
void delete_node_by_name(string street_name, TreeNode **tree) {}

// House list functions

House new_house() {}
HouseNode* new_house_node(House data) {}
void add_house(HouseNode node, HouseNode **list) {}
void remove_all_houses(HouseNode **list) {}
void remove_house(string number, HouseNode **list) {}
int list_size(HouseNode **list) {}

// File Stream functions

void save_all(TreeNode **tree) {}
TreeNode *read_files() {}
void clear_files() {}