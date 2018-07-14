//
// Created by ninja on 7/13/18.
//

#include <iostream>

using namespace std;

class Heap {
    public:
        int *arr, count, capacity;

        int parent(int child_index) {
            if(child_index <= 0 || child_index >= count)
                return -1;
            return (child_index-1)/2;
        }

        int leftChild(int parent_index) {
            int left = 2*parent_index + 1;
            if(left >= count)
                return -1;
            return left;
        }

        int rightChild(int parent_index) {
            int right = 2*parent_index + 2;
            if(right >= count)
                return -1;
            return right;
        }

        void resizeHeap(int ext) {
            int *arr_old = arr;
            arr = new int[capacity + ext];
            if(arr == nullptr) {
                cout<<"Memory error.\n";
                return;
            }

            for (int i = 0; i < capacity; ++i)
                arr[i] = arr_old[i];

            capacity += ext;
            delete arr_old;
        }

        Heap(int h_capacity) {
            capacity = h_capacity;
            count = 0;
            arr = new int[capacity];
            if(arr == nullptr) {
                cout<<"Memory error\n";
                return;
            }
            cout<<"Heap is initialized\n";
        }

        int maxElement() {
            if(count == 0)
                return -1;
            return arr[0];
        }

        void heapifyDown(int i) {
            int l, r, max, temp;
            l = leftChild(i);
            r = rightChild(i);

            if(l != -1 && arr[l] > arr[i])
                max = l;
            else
                max = i;
            if(r != -1 && arr[r] > arr[max])
                max = r;

            if(max != i) {
                temp = arr[i];
                arr[i] = arr[max];
                arr[max] = temp;
                heapifyDown(max);
            }
        }

        void heapifyUp(int i) {
            int temp;
            while (i >= 0 && arr[i] > arr[(i-1)/2]) {
                temp = arr[i];
                arr[i] = arr[(i-1)/2];
                arr[(i-1)/2] = temp;
                i = (i-1)/2;
            }
        }

        void buildHeap(int *a, int n) {
            while (n > capacity) {
                cout << "Elements in input exceed allocated capacity. Resizing heap by a factor of 2...\n";
                resizeHeap(n - capacity);
            }

            count = n;
            for (int i = 0; i < n; ++i)
                arr[i] = a[i];

            for (int i = (n-1)/2; i >= 0; i--)
                heapifyDown(i);

        }

        void insert(int data) {
            if(count == capacity)
                resizeHeap(1);
            arr[count++] = data;
            heapifyUp(count);
        }

        int deleteMax() {
            if(count == 0)
                return -1;
            int data = arr[0];
            arr[0] = arr[count-1];
            count--;
            heapifyDown(0);
            return data;
        }

        void printHeap() {
            if(count == 0) {
                cout << "Heap is empty\n";
                return;
            }
            cout<<"Heap: ";
            for (int i = 0; i < capacity; ++i) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        int* getHeap() {
            return arr;
        }

        void destroyHeap() {
            if(arr == nullptr)
                return;
            delete arr;
        }
};
