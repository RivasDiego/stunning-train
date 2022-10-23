#include "structs.hpp"
using namespace std;

// List functions

void AddAtStart (T data, Node **list);
void AddAtEnd (T data, Node **list);
void AddAfter (T data, Node **list, string word);
void AddBefore (T data, Node **list, string word);

void RemoveAtStart (Node** list);
void RemoveAtEnd (Node** list);
void RemoveAfter (Node** list, string word);
void RemoveBefore (Node** list, string word);
void RemoveWord (Node** list, string word);


Node* CreateNode(Word element);
void _init_();
bool IsEmpty(Node **list);
void PrintList(Node **list);
void EnoughSpace(T data, Node **list);

// File Stream Functions

void SaveToFile();
void ReadFile();

// Word Functions

Word CreateWord();
Word GetFirst(Node** list);
Word GetLast(Node** list);
Word GetWordInfo(Node** list);
void PrintWord(string word);
void PrintWord(Word word);
