#include <iostream>
#include <string>
#include <algorithm>

#include "lib/functions.hpp"

using namespace std;

HouseNode* new_house_node(House element)
{
    HouseNode* p__node = new HouseNode;
    p__node->element = element;
    p__node->next = NULL;
    return p__node;
}

void add_house(House data, HouseNode **list)
{
    HouseNode* p__node = new_house_node(data);

    if (list_empty(*list))
        *list = p__node;
    else
    {
        HouseNode *temp_pointer1 = *list;
        HouseNode *temp_pointer2 = NULL;

        while (temp_pointer1 != NULL)
        {
            temp_pointer2 = temp_pointer1;
            temp_pointer1 = temp_pointer1->next;
        }

        temp_pointer2->next = p__node;
    }
    return;
}

bool list_empty(HouseNode *list)
{
    return list == NULL;
}

HouseNode* find_house_node(HouseNode *list, string number)
{
    HouseNode *temp_pointer = list;

    if (list_empty(list))
        return NULL;
    string numberToUpper = number;
    string search_numberToUpper = temp_pointer->element.number;

    transform(number.begin(), number.end(), numberToUpper.begin(), ::toupper);
    transform(temp_pointer->element.number.begin(), temp_pointer->element.number.end(), search_numberToUpper.begin(), ::toupper);

    while (search_numberToUpper != numberToUpper)
    {
        temp_pointer = temp_pointer->next;
        if (temp_pointer == NULL)
        {
            return NULL;
        }
        search_numberToUpper = temp_pointer->element.number;
        transform(temp_pointer->element.number.begin(), temp_pointer->element.number.end(), search_numberToUpper.begin(), ::toupper);
    };

    return temp_pointer;
}

HouseNode *find_house_node_before(HouseNode **list, string number)
{
    HouseNode *temp_pointer1 = *list;
    HouseNode *temp_pointer2 = NULL;

    if (list_empty(*list))
        return NULL;

    string numberToUpper = number;
    string search_numberToUpper = temp_pointer1->element.number;
    transform(number.begin(), number.end(), numberToUpper.begin(), ::toupper);
    transform(temp_pointer1->element.number.begin(), temp_pointer1->element.number.end(), search_numberToUpper.begin(), ::toupper);

    while (search_numberToUpper != numberToUpper)
    {
        temp_pointer2 = temp_pointer1;
        temp_pointer1 = temp_pointer1->next;
        if (temp_pointer1 == NULL)
        {
            return NULL;
        }
        search_numberToUpper = temp_pointer1->element.number;
        transform(temp_pointer1->element.number.begin(), temp_pointer1->element.number.end(), search_numberToUpper.begin(), ::toupper);
    };

    return temp_pointer2;
}

void print_list(HouseNode *list)
{
    if (list_empty(list))
    {
        cout << "\nLa lista de registros esta vacia...\n";
        return;
    }

    HouseNode *temp_pointer = new HouseNode();
    temp_pointer = list;

    cout << "\n------------ CASAS EN LA CALLE -------------";
    print_house(temp_pointer->element);

    while (temp_pointer->next != NULL)
    {
        temp_pointer = temp_pointer->next;
        print_house(temp_pointer->element);
    };
    cout << "\n-------------FIN DE IMPRESION---------------\n";
    return;
}

void remove_house(HouseNode **list, string number)
{
    HouseNode* temp_pointer1 = find_house_node((*list), number);
    HouseNode* temp_pointer2 = find_house_node_before(list, number);

    if (temp_pointer1 == NULL){
        cout << "\n\t\t***ERROR***\nNo se encontro el registro...\n";
        return;
    }

    if(temp_pointer2 != NULL)
    {
        (temp_pointer2)->next = (temp_pointer1)->next;
        temp_pointer1->next = NULL;
        cout << "\nLa operacion se ejecuto exitosamente\n";
        return;
    }else{
        *list = temp_pointer1->next;
        cout << "\nLa operacion se ejecuto exitosamente\n";
        return;
    }
    
    return;

}