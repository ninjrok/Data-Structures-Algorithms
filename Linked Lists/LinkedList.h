//
// Created by ninja on 5/12/17.
//

#include <cstddef>

#define EMPTY -99999

template<class T>
struct Node {
    T value;
    Node<T> *next;
};

template<class T>
class LinkedList {
    Node<T> *head;

    public:
        LinkedList();
        void insert(T x);
        void insertAt(T x, int position);
        T remove();
        T removeAt(int position);
        int count();
        T* listAsArray();
        bool isEmpty();

};

template<class T>
LinkedList<T>::LinkedList() {
    head = new Node<T>;
    head->value = EMPTY;
    head->next = NULL;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    if(head->value == EMPTY)
        return true;
    else
        return false;
}

template<class T>
void LinkedList<T>::insert(T x) {
    Node<T> *new_node = new Node<T>;
    new_node->value = x;
    if(isEmpty())
        new_node->next = NULL;
    else
        new_node->next = head;
    head = new_node;
}

template<class T>
void LinkedList<T>::insertAt(T x, int position) {
    Node<T> *new_node = new Node<T>;
    new_node->value = x;
    if (isEmpty()) {
        new_node->next = NULL;
        head = new_node;
    }
    else {
        Node<T> *ptr = head;
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

template<class T>
T LinkedList<T>::remove() {
    int value;
    if(head->next == NULL) {
        value = head->value;
        head->value = EMPTY;
    }
    else {
        value = head->value;
        head = head->next;
    }
    return value;
}

template<class T>
T LinkedList<T>::removeAt(int position) {
    Node<T> *ptr = head;
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

template<class T>
int LinkedList<T>::count() {
    int count = 0;
    Node<T> *ptr = head;
    if(!isEmpty())
        count++;
    while(ptr->next != NULL) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

template<class T>
T * LinkedList<T>::listAsArray() {
    Node<T> *ptr = head;
    int size = count() + 1;
    T* list = new T[size]();
    int index = 0;
    if(!isEmpty()) {
        list[index++] = ptr->value;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            list[index++] = ptr->value;
        }
    }
    list[index] = EMPTY;
    return list;
}