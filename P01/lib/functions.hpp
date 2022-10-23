#include "structs.hpp"
using namespace std;

// List functions

void AddAtStart(T data, Node **list);             // TODO Add documentation to function
void AddAtEnd(T data, Node **list);               // TODO Add documentation to function
void AddAfter(T data, Node **list, string word);  // TODO Add documentation to function
void AddBefore(T data, Node **list, string word); // TODO Add documentation to function

void RemoveAtStart(Node **list);             // TODO Add documentation to function
void RemoveAtEnd(Node **list);               // TODO Add documentation to function
void RemoveWord(Node **list, string word);   // TODO Add documentation to function

Node *CreateNode(Word element);        // TODO Add documentation to function
bool IsEmpty(Node **list);             // TODO Add documentation to function
void PrintList(Node **list);           // TODO Add documentation to function
void EnoughSpace(T data, Node **list); // TODO Add documentation to function

// File Stream Functions

void SaveToFile(); // TODO Add documentation to function
void ReadFile();   // TODO Add documentation to function

// Word Functions

Word CreateWord();             // TODO Add documentation to function
Word GetFirst(Node **list);    // TODO Add documentation to function
Word GetLast(Node **list);     // TODO Add documentation to function
Word GetWordInfo(Node **list); // TODO Add documentation to function
void PrintWord(string word);   // TODO Add documentation to function
void PrintWord(Word word);     // TODO Add documentation to function
