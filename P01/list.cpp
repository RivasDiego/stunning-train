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

    if (IsEmpty(list))
        *list = p__node;
    else
    {
        Node *temp_pointer1 = findNode(list, word);
        Node *temp_pointer2 = findNodeBefore(list, word);

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

    if (IsEmpty(list))
        *list = p__node;
    else
    {
        Node *temp_pointer1 = findNode(list, word);
        Node *temp_pointer2 = findNodeBefore(list, word);

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
void RemoveWord(Node **list, string word)
{
    Node *temp_pointer = findNode(list, word);
}

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

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        PrintWord(temp_pointer->element);
    };
    cout << "\n--------------------------------------------";
    return;
}
void EnoughSpace(T data, Node **list); // TODO Implement EnoughSpace function;
Node *findNode(Node **list, string word)
{
    Node *temp_pointer = *list;

    string wordToUpper = word;
    string searchWordToUpper = temp_pointer->element.word;

    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);
    transform(temp_pointer->element.word.begin(), temp_pointer->element.word.end(), searchWordToUpper.begin(), ::toupper);

    while (searchWordToUpper != wordToUpper)
    {
        temp_pointer = temp_pointer->next;
        if (temp_pointer == NULL)
        {
            cout << "No se pudo encontrar el registro...";
            return NULL;
        }
        searchWordToUpper = temp_pointer->element.word;
        transform(temp_pointer->element.word.begin(), temp_pointer->element.word.end(), searchWordToUpper.begin(), ::toupper);
    };

    return temp_pointer;
}
Node *findNodeBefore(Node **list, string word)
{
    Node *temp_pointer1 = *list;
    Node *temp_pointer2 = NULL;

    string wordToUpper = word;
    string searchWordToUpper = temp_pointer1->element.word;
    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);
    transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);

    while (searchWordToUpper != wordToUpper)
    {
        temp_pointer2 = temp_pointer1;
        temp_pointer1 = temp_pointer1->next;
        if (temp_pointer1 == NULL)
        {
            cout << "No se pudo encontrar el registro...";
            return NULL;
        }
        searchWordToUpper = temp_pointer1->element.word;
        transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);
    };

    return temp_pointer2;
}

// File Stream Functions

void SaveToFile(); // TODO Implement SaveToFile function
void ReadFile();   // TODO Implement ReadFile function

// Word Functions

Word CreateWord()
{
    Word p__word;
    cout << "Ingresa la palabra que quieres agregar: ";
    getline(cin, p__word.word);
    cout << "Ingresa su definicion: ";
    getline(cin, p__word.def);
    cout << "Escribe separado por comas si tiene sinonimos (Presiona 'Enter' si no tiene): ";
    getline(cin, p__word.synonyms);
    cout << "Escribe separado por comas si tiene antonimos (Presiona 'Enter' si no tiene): ";
    getline(cin, p__word.antonyms);

    if (p__word.antonyms == "")
        p__word.antonyms = "Sin registros";

    if (p__word.synonyms == "")
        p__word.synonyms = "Sin registros";

    return p__word;
}

Word GetFirstWord(Node **list)
{
    return (*list)->element;
}
Word GetLastWord(Node **list)
{
    Node *temp_pointer = new Node();

    temp_pointer = *list;
    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
    };

    return (temp_pointer)->element;
}

Word GetWord(Node **list, string word)
{
    Node *temp_pointer = *list;

    string wordToUpper = word;
    string searchWordToUpper = temp_pointer->element.word;

    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);
    transform(temp_pointer->element.word.begin(), temp_pointer->element.word.end(), searchWordToUpper.begin(), ::toupper);

    while (searchWordToUpper != wordToUpper)
    {
        temp_pointer = temp_pointer->next;
        if (temp_pointer == NULL)
        {
            cout << "No se pudo encontrar el registro...";
            return invalidData;
        }
        searchWordToUpper = temp_pointer->element.word;
        transform(temp_pointer->element.word.begin(), temp_pointer->element.word.end(), searchWordToUpper.begin(), ::toupper);
    };

    return (temp_pointer)->element;
}

void PrintWord(Word word)
{
    if (word.def == "INVALID DATA")
    {
        cout << "\nERROR!\n\tNo se puede imprimir el registro...";
        return;
    }
    cout << "\n--------------------------------------------";
    cout << "\nPalabra: " << word.word;
    cout << "\nDefinicion: " << word.def;
    cout << "\nSinonimos: " << word.synonyms;
    cout << "\nAntonimos: " << word.antonyms;
    cout << "\n--------------------------------------------";
    return;
}
