//
// Created by ninja on 7/13/18.
//

#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    int *a, n;
    cout<<"Enter n: ";
    cin>>n;

    a = new int[n];
    cout<<"Enter heap array in any order: ";
    for (int i = 0; i < n; i++)
        cin>>a[i];

    Heap h = Heap(n);
    h.buildHeap(a, n);
    h.printHeap();

    return 0;
}