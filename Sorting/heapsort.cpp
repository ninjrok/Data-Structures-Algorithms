//
// Created by ninja on 7/13/18.
//

#include <iostream>
#include "../Heaps/Heap.h"

using namespace std;

class HeapSort: Heap {
    public:
        HeapSort(int *a, int n): Heap(n) {
            int temp, heap_size=n;
            buildHeap(a, n);
            printHeap();

            for (int i = n-1; i >= 0; i--) {
                temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;
                count -= 1;
                heapifyDown(0);
            }

            cout<<"Sorted array: ";
            for (int i = 0; i < heap_size; ++i) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};


int main() {
    int *a, n, temp, *heap;

    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter array: ";
    a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    HeapSort hs = HeapSort(a, n);

    return 0;
}