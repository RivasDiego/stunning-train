#include <iostream>
#include <fstream>
#include <string>
#include "lib/functions.hpp"

using namespace std;

// List functions

void AddAtStart (T data, Node **list)
{
    Node* p__node = CreateNode(data);
    
    p__node->next = *list;
    *list = p__node;

}
void AddAtEnd (T data, Node **list);
void AddAfter (T data, Node **list, string word);
void AddBefore (T data, Node **list, string word);

void RemoveAtStart (Node** list);
void RemoveAtEnd (Node** list);
void RemoveAfter (Node** list, string word);
void RemoveBefore (Node** list, string word);
void RemoveWord (Node** list, string word);

Node* CreateNode(T element)
{
    Node *p__node  = new Node;
    p__node->element = element;
    p__node->next = NULL;
    return p__node;
}
void _init_();
bool IsEmpty(Node **list)
{
    return *list == NULL;
}
void PrintList(Node **list)
{
    if (*list == NULL)
    {
        cout << "\nLista vacia...";
        return;
    }

    Node *temp_pointer = new Node();
    temp_pointer = *list;

    cout << "\n--------------------------------------------";
    PrintWord(temp_pointer->element);
    cout << "\n--------------------------------------------";
    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        PrintWord(temp_pointer->element);
        cout << "\n--------------------------------------------";
    };
    delete temp_pointer;
    return;
}
void EnoughSpace(T data, Node **list);

// File Stream Functions

void SaveToFile();
void ReadFile();

// Word Functions

Word CreateWord();
Word GetFirst(Node** list);
Word GetLast(Node** list);
Word GetWordInfo(Node** list);
void PrintWord(Word word)
{
    cout << "\nPalabra: " << word.word;
    cout << "\nDefinicion: " << word.def;
    cout << "\nSinonimos: " << word.synonyms;
    cout << "\nAntonimos: " << word.antonyms;
    return;
}
