//
// Created by ninja on 5/13/17.
//
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int choice, i, position;

    // Initialization for int template
    int value;
    int* list;
    LinkedList<int> linkedList;

    // Initialization for float template
//    float value;
//    float* list;
//    LinkedList<float> linkedList;

    cout<<"Linked list is initialized.\n";
    do {
        cout << "Linked list operations:\n1. Insert at beginning\n2. Remove from beginning"
                "\n3. Number of elements\n4. Display list\n5. Insert at position\n6. Delete at position"
                "\n7. Exit\nEnter Choice: ";
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                linkedList.insert(value);
                break;
            case 2:
                cout<<"Popping from list, value of popped element= "<<linkedList.remove()<<endl;
                break;
            case 3:
                cout<<"Count of elements= "<<linkedList.count()<<endl;
                break;
            case 4:
                cout<<"The list: \n";
                i = 0;
                list = linkedList.listAsArray();
                while(list[i] != EMPTY)
                    cout<<list[i++]<<" --> ";
                cout<<endl;
                break;
            case 5:
                cout<<"Enter value: ";
                cin>>value;
                cout<<"Enter position: ";
                cin>>position;
                linkedList.insertAt(value, position);
                cout<<"Insertion of "<<value<<" completed at position "<<position<<endl;
                break;
            case 6:
                cout<<"Enter position: ";
                cin>>position;
                cout<<"Popping from the "<<position<<" th position, value= "<<linkedList.removeAt(position)<<endl;
                break;
            case 7:
                continue;
            default:
                cout<<"Invalid input. Try again.\n";
        }
    } while (choice != 7);
    cout<<"Exiting...\n";

    return 0;
}
