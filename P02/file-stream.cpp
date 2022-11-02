#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

const char first_names_file_address [] = "res/fnames_dataFile.txt";
const char last_names_file_address [] = "res/lnames_dataFile.txt";
const char phone_numbers_file_address [] = "res/phones_dataFile.txt";
const char emails_file_address [] = "res/emails_dataFile.txt";

void SaveToFiles(Node **list)
{
    ClearFiles();

    fstream fnames_dataFile(first_names_file_address, ios::out | ios::app);
    fstream lnames_dataFile(last_names_file_address, ios::out | ios::app);
    fstream phones_dataFile(phone_numbers_file_address, ios::out | ios::app);
    fstream emails_dataFile(emails_file_address, ios::out | ios::app);

    if (IsEmpty(list))
        return;

    Node *temp_pointer = new Node();
    temp_pointer = *list;

    fnames_dataFile << "\n"
                   << temp_pointer->element.first_names;
    lnames_dataFile << "\n"
                  << temp_pointer->element.last_names;
    phones_dataFile << "\n"
                  << temp_pointer->element.phone_number;
    emails_dataFile << "\n"
                  << temp_pointer->element.email;

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        fnames_dataFile << "\n"
                       << temp_pointer->element.first_names;
        lnames_dataFile << "\n"
                      << temp_pointer->element.last_names;
        phones_dataFile << "\n"
                      << temp_pointer->element.phone_number;
        emails_dataFile << "\n"
                      << temp_pointer->element.email;
    };
    return;
}

Node *ReadFiles()
{
    Node *p__list = NULL;

    fstream fnames_dataFile(first_names_file_address, ios::out | ios::app);
    fnames_dataFile.close();
    fnames_dataFile.open(first_names_file_address, ios::in);

    fstream lnames_dataFile(last_names_file_address, ios::out | ios::app);
    lnames_dataFile.close();
    lnames_dataFile.open(last_names_file_address, ios::in);

    fstream phones_dataFile(phone_numbers_file_address, ios::out | ios::app);
    phones_dataFile.close();
    phones_dataFile.open(phone_numbers_file_address, ios::in);

    fstream emails_dataFile(emails_file_address, ios::out | ios::app);
    emails_dataFile.close();
    emails_dataFile.open(emails_file_address, ios::in);

    string temp_string = "";
    Contact p__contact = invalidData;

    getline(fnames_dataFile, temp_string);
    p__contact.first_names = temp_string;

    getline(lnames_dataFile, temp_string);
    p__contact.last_names = temp_string;

    getline(phones_dataFile, temp_string);
    p__contact.phone_number = temp_string;

    getline(emails_dataFile, temp_string);
    p__contact.email = temp_string;

    if (p__contact.last_names != "")
        AddAtEnd(p__contact, &p__list);

    while (!fnames_dataFile.eof())
    {
        p__contact = invalidData;
        temp_string = "";

        getline(fnames_dataFile, temp_string);
        p__contact.first_names = temp_string;

        getline(lnames_dataFile, temp_string);
        p__contact.last_names = temp_string;

        getline(phones_dataFile, temp_string);
        p__contact.phone_number = temp_string;

        getline(emails_dataFile, temp_string);
        p__contact.email = temp_string;

        if (p__contact.last_names != "")
            AddAtEnd(p__contact, &p__list);
    }

    if (p__contact.first_names == "INVALID_DATA" || p__contact.first_names == "")
    {
        p__list = NULL;
        return p__list;
    }

    return p__list;
}

void ClearFiles()
{
    remove(first_names_file_address);
    remove(last_names_file_address);
    remove(phone_numbers_file_address);
    remove(emails_file_address);

    return;
}
