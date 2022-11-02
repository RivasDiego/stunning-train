#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

const char words_file_address [] = "res/words_dataFile.txt";
const char definitions_file_address [] = "res/defs_dataFile.txt";
const char synonyms_file_address [] = "res/syns_dataFile.txt";
const char antonyms_file_address [] = "res/ants_dataFile.txt";

void SaveToFiles(Node **list)
{
    ClearFiles();

    fstream words_dataFile(words_file_address, ios::out | ios::app);
    fstream defs_dataFile(definitions_file_address, ios::out | ios::app);
    fstream syns_dataFile(synonyms_file_address, ios::out | ios::app);
    fstream ants_dataFile(antonyms_file_address, ios::out | ios::app);

    if (IsEmpty(list))
        return;

    Node *temp_pointer = new Node();
    temp_pointer = *list;

    words_dataFile << "\n"
                   << temp_pointer->element.word;
    defs_dataFile << "\n"
                  << temp_pointer->element.def;
    syns_dataFile << "\n"
                  << temp_pointer->element.synonyms;
    ants_dataFile << "\n"
                  << temp_pointer->element.antonyms;

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        words_dataFile << "\n"
                       << temp_pointer->element.word;
        defs_dataFile << "\n"
                      << temp_pointer->element.def;
        syns_dataFile << "\n"
                      << temp_pointer->element.synonyms;
        ants_dataFile << "\n"
                      << temp_pointer->element.antonyms;
    };
    return;
}

Node *ReadFiles()
{
    Node *p__list = NULL;

    fstream words_dataFile(words_file_address, ios::out | ios::app);
    words_dataFile.close();
    words_dataFile.open(words_file_address, ios::in);

    fstream defs_dataFile(definitions_file_address, ios::out | ios::app);
    defs_dataFile.close();
    defs_dataFile.open(definitions_file_address, ios::in);

    fstream syns_dataFile(synonyms_file_address, ios::out | ios::app);
    syns_dataFile.close();
    syns_dataFile.open(synonyms_file_address, ios::in);

    fstream ants_dataFile(antonyms_file_address, ios::out | ios::app);
    ants_dataFile.close();
    ants_dataFile.open(antonyms_file_address, ios::in);

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

    if (p__word.def != "")
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

        if (p__word.def != "")
            AddAtEnd(p__word, &p__list);
    }

    if (p__word.word == "INVALID_DATA" || p__word.word == "")
    {
        p__list = NULL;
        return p__list;
    }

    return p__list;
}

void ClearFiles()
{
    remove(words_file_address);
    remove(definitions_file_address);
    remove(synonyms_file_address);
    remove(antonyms_file_address);

    return;
}
