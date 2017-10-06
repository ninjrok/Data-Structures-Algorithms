//
// Created by ninja on 5/14/17.
//

#include "DoublyLinkedList.h"

#include <iostream>

using namespace std;

int main() {
    int choice, value, i, position;
    int* list;
    DoublyLinkedList doublyLinkedList;
    cout<<"Doubly linked list initialized.\n";
    do {
        cout << "Doubly Linked list operations:\n1. Insert at beginning\n2. Remove from beginning"
                "\n3. Number of elements\n4. Display list\n5. Exit\nEnter Choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                doublyLinkedList.insert(value);
                break;
            case 2:
                cout << "Popping from list, value of popped element= " << doublyLinkedList.remove() << endl;
                break;
            case 3:
                cout << "Count of elements= " << doublyLinkedList.count() << endl;
                break;
            case 4:
                cout << "The list: \n";
                i = 0;
                list = doublyLinkedList.listAsArray();
                while (list[i] != NULL)
                    cout << list[i++] << " <--> ";
                cout << endl;
                break;
            case 5:
                continue;
            default:
                cout<<"Invalid input, try again.\n";
        }
    } while (choice != 5);

    return 0;
}