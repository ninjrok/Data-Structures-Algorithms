//
// Created by ninja on 5/14/17.
//

#include <cstddef>

struct Node {
    int value;
    Node *prev, *next;
};

class DoublyLinkedList {
    Node *head;

    public:
        DoublyLinkedList();
        int count();
        bool isEmpty();
        void insert(int x);
        int remove();
        int* listAsArray();
};


DoublyLinkedList::DoublyLinkedList() {
    head = new Node;
    head->value = NULL;
    head->prev = NULL;
    head->next = NULL;
}

bool DoublyLinkedList::isEmpty() {
    if(head->value == NULL)
        return true;
    else
        return false;
}

int DoublyLinkedList::count() {
    int count = 0;
    Node *ptr = head;
    if(!isEmpty())
        count++;
    while(ptr->next != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

void DoublyLinkedList::insert(int x) {
    Node *new_node = new Node;
    new_node->value = x;
    if (isEmpty()) {
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else {
        new_node->prev = head;
        new_node->next = NULL;
        head->next = new_node;
    }
    head = new_node;
}

int DoublyLinkedList::remove() {
    int value;
    if(head->next == NULL) {
        value = head->value;
        head->value = NULL;
    }
    else {
        value = head->value;
        head = head->next;
        head->prev = NULL;
    }
    return value;
}

int * DoublyLinkedList::listAsArray() {
    Node *ptr = head;
    int size = count() + 1;
    int* list = new int[size]();
    int index = 0;
    if(!isEmpty()) {
        list[index++] = ptr->value;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            list[index++] = ptr->value;
        }
    }
    list[index] = NULL;
    return list;
}