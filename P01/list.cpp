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
    cout << "La operacion se ejecuto exitosamente\n";
    return;
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
    return;
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

        if (temp_pointer1 == NULL)
        {
            cout << "\n\t\t***ERROR***\nNo se encontro el registro...\n";
            return;
        }

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
    cout << "La operacion se ejecuto exitosamente\n";
    return;
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

        if (temp_pointer1 == NULL){
            cout << "\n\t\t***ERROR***\nNo se encontro el registro...\n";
            return;
        }

        temp_pointer2 = temp_pointer1;
        temp_pointer1 = temp_pointer1->next;

        p__node->next = temp_pointer1;
        temp_pointer2->next = p__node;
    }
    cout << "La operacion se ejecuto exitosamente\n";
    return;
}

void RemoveAtStart(Node **list)
{
    if (IsEmpty(list))
        *list = NULL;
    else
        *list = (*list)->next;
    
    cout << "La operacion se ejecuto exitosamente\n";
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
    cout << "La operacion se ejecuto exitosamente\n";
    return;
}

void RemoveWord(Node **list, string word)
{
    Node *temp_pointer1 = findNode(list, word);
    Node *temp_pointer2 = findNodeBefore(list, word);

    if (temp_pointer1 == NULL){
        cout << "\n\t\t***ERROR***\nNo se encontro el registro...\n";
        return;
    }

    if(temp_pointer2 != NULL)
    {
        (temp_pointer2)->next = (temp_pointer1)->next;
        temp_pointer1->next = NULL;
        cout << "La operacion se ejecuto exitosamente\n";
        return;
    }else{
        *list = temp_pointer1->next;
        cout << "La operacion se ejecuto exitosamente\n";
        return;
    }
    
    return;

}

void RemoveAll(Node **list)
{
    
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
    if (IsEmpty(list))
    {
        cout << "\nLa lista de registros esta vacia...\n";
        return;
    }

    Node *temp_pointer = new Node();
    temp_pointer = *list;

    cout << "\n------------INICIO DE IMPRESION-------------";
    PrintWord(temp_pointer->element);

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        PrintWord(temp_pointer->element);
    };
    cout << "\n-------------FIN DE IMPRESION---------------\n";
    return;
}

bool EnoughSpace(T data, Node **list); // TODO Implement EnoughSpace function;

Node *findNode(Node **list, string word)
{
    Node *temp_pointer = *list;

    if (IsEmpty(list))
        return NULL;

    string wordToUpper = word;
    string searchWordToUpper = temp_pointer->element.word;

    transform(word.begin(), word.end(), wordToUpper.begin(), ::toupper);
    transform(temp_pointer->element.word.begin(), temp_pointer->element.word.end(), searchWordToUpper.begin(), ::toupper);

    while (searchWordToUpper != wordToUpper)
    {
        temp_pointer = temp_pointer->next;
        if (temp_pointer == NULL)
        {
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

    if (IsEmpty(list))
        return NULL;

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
            return NULL;
        }
        searchWordToUpper = temp_pointer1->element.word;
        transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);
    };

    return temp_pointer2;
}
