//
// Created by ninja on 5/12/17.
//

#include <cstddef>

struct Node {
    int value;
    Node *next;
};

class LinkedList {
    Node *head;

    public:
        LinkedList();
        void insert(int x);
        void insertAt(int x, int position);
        int remove();
        int removeAt(int position);
        int count();
        int* listAsArray();
        bool isEmpty();

};

LinkedList::LinkedList() {
    head = new Node;
    head->value = NULL;
    head->next = NULL;
}

bool LinkedList::isEmpty() {
    if(head->value == NULL)
        return true;
    else
        return false;
}

void LinkedList::insert(int x) {
    Node *new_node = new Node;
    new_node->value = x;
    if(isEmpty())
        new_node->next = NULL;
    else
        new_node->next = head;
    head = new_node;
}

void LinkedList::insertAt(int x, int position) {
    Node *new_node = new Node;
    new_node->value = x;
    if (isEmpty()) {
        new_node->next = NULL;
        head = new_node;
    }
    else {
        Node *ptr = head;
        int iter = count() - position;
        if (iter <= 0)
            new_node->next = ptr;
        else if (iter > 0) {
            for (int i = 1; i < iter; i++)
                ptr = ptr->next;
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
}

int LinkedList::remove() {
    int value;
    if(head->next == NULL) {
        value = head->value;
        head->value = NULL;
    }
    else {
        value = head->value;
        head = head->next;
    }
    return value;
}

int LinkedList::removeAt(int position) {
    Node *ptr = head;
    int value;
    if (! isEmpty()) {
        int iter = count() - position;
        if (iter <= 0) {
            value = head->value;
            head = head->next;
        }
        else {
            for (int i = 0; i < iter; i++)
                ptr = ptr->next;
            if (ptr->next != NULL && ptr->next->next != NULL) {
                value = ptr->next->value;
                ptr->next = ptr->next->next;
            }
            else if (ptr->next != NULL && ptr->next->next == NULL) {
                value = ptr->next->value;
                ptr->next = NULL;
            }
        }
        return value;
    }
}

int LinkedList::count() {
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

int * LinkedList::listAsArray() {
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