#include <iostream>
using namespace std;

struct contact
{
    string first_names;
    string last_names;
    string phone_number;
    string email;
};
typedef struct contact Contact;

typedef Contact T;

struct node
{
    T element;
    struct node *next;
};

typedef struct node Node;

const Contact invalidData = {"INVALID_DATA", "INVALID_DATA", "INVALID_DATA", "INVALID_DATA"};
