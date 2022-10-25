#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

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