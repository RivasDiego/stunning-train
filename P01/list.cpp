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

        if (temp_pointer1 == NULL)
            return;

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

        if (temp_pointer1 == NULL)
            return;

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
    Node *temp_pointer1 = findNode(list, word);
    Node *temp_pointer2 = findNodeBefore(list, word);

    if (temp_pointer1 == NULL)
        return;

    (temp_pointer2)->next = (temp_pointer1)->next;
    temp_pointer1->next = NULL;
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

    cout << "\n------------INICIO DE IMPRESION-------------";
    PrintWord(temp_pointer->element);

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        PrintWord(temp_pointer->element);
    };
    cout << "\n-------------FIN DE IMPRESION---------------";
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
            return NULL;
        }
        searchWordToUpper = temp_pointer1->element.word;
        transform(temp_pointer1->element.word.begin(), temp_pointer1->element.word.end(), searchWordToUpper.begin(), ::toupper);
    };

    return temp_pointer2;
}

// File Stream Functions

void SaveToFiles()
{
    /*     void WriteTimeToFile(string time)
    {
        ofstream data_file ("res/data_file.txt", ios::app);
        data_file << time;
        data_file.close();
    }
    void ReadTimeOfFile()
    {
        ifstream data_file ("res/data_file.txt");
        string time,time2,time3,time4,time5;
        while (data_file >> time >> time2 >> time3 >> time4 >> time5)
        {
            cout << time << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << "\n";
        }

        return;
    } */
} // TODO Implement SaveToFile function
Node *ReadFiles()
{
    Node *p__list = NULL;

    fstream words_dataFile("res/words_dataFile.txt", ios::out | ios::app);
    words_dataFile.close();
    words_dataFile.open("res/words_dataFile.txt", ios::in);

    fstream defs_dataFile("res/defs_dataFile.txt", ios::out | ios::app);
    defs_dataFile.close();
    defs_dataFile.open("res/defs_dataFile.txt", ios::in);

    fstream syns_dataFile("res/syns_dataFile.txt", ios::out | ios::app);
    syns_dataFile.close();
    syns_dataFile.open("res/syns_dataFile.txt", ios::in);

    fstream ants_dataFile("res/ants_dataFile.txt", ios::out | ios::app);
    ants_dataFile.close();
    ants_dataFile.open("res/ants_dataFile.txt", ios::in);

    string temp_string = "";
    Word p__word = invalidData;

    getline(words_dataFile, temp_string);
    p__word.word = temp_string;

    getline(defs_dataFile, temp_string);
    p__word.def = temp_string;

    getline(syns_dataFile, temp_string);
    p__word.synonyms = temp_string;

    getline(ants_dataFile, temp_string);
    p__word.antonyms = temp_string;

    AddAtEnd(p__word, &p__list);
    
    while (!words_dataFile.eof())
    {
        p__word = invalidData;
        temp_string = "";

        getline(words_dataFile, temp_string);
        p__word.word = temp_string;

        getline(defs_dataFile, temp_string);
        p__word.def = temp_string;

        getline(syns_dataFile, temp_string);
        p__word.synonyms = temp_string;

        getline(ants_dataFile, temp_string);
        p__word.antonyms = temp_string;
        
        AddAtEnd(p__word, &p__list);
    }

    if (p__word.word == "INVALID_DATA")
        return p__list = NULL;
    
    return p__list;
    
    
}

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
    Node *temp_pointer = findNode(list, word);
    if (temp_pointer == NULL)
        return invalidData;
    else
        return (temp_pointer)->element;
}

void PrintWord(Word word)
{
    if (word.def == "INVALID_DATA")
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

void PrintWord(string word, Node **list)
{
    Node *temp_pointer = findNode(list, word);
    PrintWord(temp_pointer->element);
    return;
}
