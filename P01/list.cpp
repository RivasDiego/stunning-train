#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

// List functions

void AddAtStart(T data, Node **list)
{
    Node *p__node = CreateNode(data);

    p__node->next = *list;
    *list = p__node;
}
void AddAtEnd(T data, Node **list)
{
    Node *p__node = CreateNode(data);

    if (IsEmpty(list))
        *list = p__node;
    else
    {
        Node *temp_pointer1 = *list;
        Node *temp_pointer2 = NULL;

        while (temp_pointer1 != NULL)
        {
            temp_pointer2 = temp_pointer1;
            temp_pointer1 = temp_pointer1->next;
        }

        temp_pointer2->next = p__node;
    }
}
void AddBefore(T data, Node **list, string word)
{
    Node *p__node = CreateNode(data);

    string wordToUpper = word;
    string searchWordToUpper = "";
    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);

    if (IsEmpty(list))
        *list = p__node;
    else
    {
        Node *temp_pointer1 = *list;
        Node *temp_pointer2 = NULL;

        searchWordToUpper = temp_pointer1->element.word;
        transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);

        while (searchWordToUpper != wordToUpper)
        {
            temp_pointer2 = temp_pointer1;
            temp_pointer1 = temp_pointer1->next;
            if (temp_pointer1 == NULL)
            {
                cout << "-No lo encontre we.- ";
                return;
            }
            searchWordToUpper = temp_pointer1->element.word;
            transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);
        };

        if (temp_pointer2 == NULL)
        {
            p__node->next = *list;
            *list = p__node;
        }
        else
        {
            p__node->next = temp_pointer1;
            temp_pointer2->next = p__node;
        }
    }
}
void AddAfter(T data, Node **list, string word)
{
    Node *p__node = CreateNode(data);

    string wordToUpper = word;
    string searchWordToUpper = "";
    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);

    if (IsEmpty(list))
        *list = p__node;
    else
    {
        Node *temp_pointer1 = *list;
        Node *temp_pointer2 = NULL;

        searchWordToUpper = temp_pointer1->element.word;
        transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);

        while (searchWordToUpper != wordToUpper)
        {
            temp_pointer2 = temp_pointer1;
            temp_pointer1 = temp_pointer1->next;
            if (temp_pointer1 == NULL)
            {
                cout << "-No lo encontre we.- ";
                return;
            }
            searchWordToUpper = temp_pointer1->element.word;
            transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);
        };

        temp_pointer2 = temp_pointer1;
        temp_pointer1 = temp_pointer1->next;

        p__node->next = temp_pointer1;
        temp_pointer2->next = p__node;
    }
}
void RemoveAtStart(Node **list)
{
    if (IsEmpty(list))
        *list = NULL;
    else
        *list = (*list)->next;
    return;
}
void RemoveAtEnd(Node **list)
{
    if (IsEmpty(list))
        *list = NULL;
    else
    {
        Node *temp_pointer1 = *list;
        Node *temp_pointer2 = NULL;

        while (temp_pointer1->next != NULL)
        {
            temp_pointer2 = temp_pointer1;
            temp_pointer1 = temp_pointer1->next;
        }

        temp_pointer2->next = NULL;
    }
}
void RemoveAfter(Node **list, string word);  // TODO Implement RemoveAfter function
void RemoveBefore(Node **list, string word); // TODO Implement RemoveBefore function
void RemoveWord(Node **list, string word);   // TODO Implement RemoveWord function

Node *CreateNode(T element)
{
    Node *p__node = new Node;
    p__node->element = element;
    p__node->next = NULL;
    return p__node;
}
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
    return;
}
void EnoughSpace(T data, Node **list); // TODO Implement EnoughSpace function;

// File Stream Functions

void SaveToFile(); // TODO Implement SaveToFile function
void ReadFile();   // TODO Implement ReadFile function

// Word Functions

Word CreateWord();             // TODO Implement CreateWord function
Word GetFirst(Node **list);    // TODO Implement GetFirst function
Word GetLast(Node **list);     // TODO Implement GetLast function
Word GetWordInfo(Node **list); // TODO Implement GetWordInfo function
void PrintWord(Word word)
{
    cout << "\nPalabra: " << word.word;
    cout << "\nDefinicion: " << word.def;
    cout << "\nSinonimos: " << word.synonyms;
    cout << "\nAntonimos: " << word.antonyms;
    return;
}
