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
    struct node* next;
};

typedef struct node Node;

void AddAtStart (T data, Node **list);
void AddAtEnd (T data, Node **list);
void AddAfter (T data, Node **list);
void AddBefore (T data, Node **list);

void RemoveAtStart (Node** list);
void RemoveAtEnd (Node** list);
void RemoveAfter (Node** list);
void RemoveBefore (Node** list);

void SaveToFile();
void _init_();

Word GetFirst(Node** list);
Word GetLast(Node** list);
Word GetWordInfo(Node** list);

string DateTimeStamp ();