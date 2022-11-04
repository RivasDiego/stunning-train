#include <iostream>
#include "lib/functions.hpp"

using namespace std;

Street new_street() {}
TreeNode new_node(Street data) {}
void add_node(TreeNode node, TreeNode **tree) {}
void search_node_by_id(int ID, TreeNode **tree) {}
void search_node_by_name(string street_name, TreeNode **tree) {}
void delete_node_by_id(int ID, TreeNode **tree) {}
void delete_node_by_name(string street_name, TreeNode **tree) {}