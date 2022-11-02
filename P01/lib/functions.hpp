#include "structs.hpp"
using namespace std;

// List functions

void AddAtStart(T data, Node **list);             // TODO Add documentation to function
void AddAtEnd(T data, Node **list);               // TODO Add documentation to function
void AddAfter(T data, Node **list, string word);  // TODO Add documentation to function
void AddBefore(T data, Node **list, string word); // TODO Add documentation to function
bool EnoughSpace(T data, Node **list);            // TODO Add documentation to function

void RemoveAtStart(Node **list);           // TODO Add documentation to function
void RemoveAtEnd(Node **list);             // TODO Add documentation to function
void RemoveWord(Node **list, string word); // TODO Add documentation to function
void RemoveAll(Node **list);               // TODO Add documentation to function

Node *CreateNode(Word element);                 // TODO Add documentation to function
bool IsEmpty(Node **list);                      // TODO Add documentation to function
void PrintList(Node **list);                    // TODO Add documentation to function
Node *findNode(Node **list, string word);       // TODO Add documentation to function
Node *findNodeBefore(Node **list, string word); // TODO Add documentation to function

// File Stream Functions

void SaveToFiles(Node **list); // TODO Add documentation to function
Node *ReadFiles();             // TODO Add documentation to function
void ClearFiles();             // TODO Add documentation to function

// Word Functions

Word CreateWord();                        // TODO Add documentation to function
Word GetFirstWord(Node **list);           // TODO Add documentation to function
Word GetLastWord(Node **list);            // TODO Add documentation to function
Word GetWord(Node **list, string word);   // TODO Add documentation to function
void PrintWord(string word, Node **list); // TODO Add documentation to function
void PrintWord(Word word);                // TODO Add documentation to function
