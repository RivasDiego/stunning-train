#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

void SaveToFiles(Node** list)
{
    /*     void WriteTimeToFile(string time)
        {
            ofstream data_file ("res/data_file.txt", ios::app);
            data_file << time;
            data_file.close();
        }
    */
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

    if (p__word.word == "INVALID_DATA" || p__word.word == "")
    {
        p__list = NULL;
        return p__list;
    }

    return p__list;
}
