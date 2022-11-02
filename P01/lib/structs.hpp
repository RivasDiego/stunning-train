#include <iostream>
using namespace std;

struct word
{
    string word;
    string def;
    string antonyms;
    string synonyms;
};
typedef struct word Word;

typedef Word T;

struct node
{
    T element;
    struct node *next;
};

typedef struct node Node;

const Word invalidData = {"INVALID_DATA", "INVALID_DATA", "INVALID_DATA", "INVALID_DATA"};
