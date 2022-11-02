#include "structs.hpp"
using namespace std;

// List functions

void AddAtStart(T data, Node **list);                     // TODO Add documentation to function
void AddAtEnd(T data, Node **list);                       // TODO Add documentation to function
void AddAfter(T data, Node **list, string phone_number);  // TODO Add documentation to function
void AddBefore(T data, Node **list, string phone_number); // TODO Add documentation to function
bool EnoughSpace(T data, Node **list);                    // TODO Add documentation to function

void RemoveAtStart(Node **list);                      // TODO Add documentation to function
void RemoveAtEnd(Node **list);                        // TODO Add documentation to function
void RemoveContact(Node **list, string phone_number); // TODO Add documentation to function
void RemoveAll(Node **list);                          // TODO Add documentation to function

Node *CreateNode(Contact element);                      // TODO Add documentation to function
bool IsEmpty(Node **list);                              // TODO Add documentation to function
void PrintList(Node **list);                            // TODO Add documentation to function
Node *findNode(Node **list, string phone_number);       // TODO Add documentation to function
Node *findNodeBefore(Node **list, string phone_number); // TODO Add documentation to function

// File Stream Functions

void SaveToFiles(Node **list); // TODO Add documentation to function
Node *ReadFiles();             // TODO Add documentation to function
void ClearFiles();             // TODO Add documentation to function

// Contact Functions

Contact CreateContact();                              // TODO Add documentation to function
Contact GetFirstContact(Node **list);                 // TODO Add documentation to function
Contact GetLastContact(Node **list);                  // TODO Add documentation to function
Contact GetContact(Node **list, string phone_number); // TODO Add documentation to function
void PrintContact(string phone_number, Node **list);  // TODO Add documentation to function
void PrintContact(Contact contact);                   // TODO Add documentation to function
