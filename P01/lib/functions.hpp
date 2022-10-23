#include "structs.hpp"
using namespace std;

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

// TODO Save to external files at the end of the execution
// TODO Read info and parse it to a list at program start