//
// Created by niranjan on 6/12/18.
//
#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    LinkedList<int> linkedList;
    int i=0;

    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);
    linkedList.insert(6);

    cout<<"Head = "<<linkedList.head->value<<endl;

    int* list = linkedList.listAsArray();
    while(list[i] != EMPTY)
        cout<<list[i++]<<" --> ";
    cout<<endl;

    Node<int> *slowPtr=linkedList.head, *fastPtr=linkedList.head;
    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    cout<<"Middle element is "<<slowPtr->value<<endl;
    return 0;
}
