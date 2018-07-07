//
// Created by ninja on 7/7/18.
//
#include <iostream>

using namespace std;


int linear_search(int n, int a[], int k) {
    for(int i=0;i<n;i++)
        if(a[i] == k)
            return i;

    return -1;
}

int main() {
    int n, a[20], k;

    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter array: ";
    for (int i = 0; i < n; ++i)
        cin>>a[i];

    cout<<"Enter search element: ";
    cin>>k;

    int index = linear_search(n, a, k);

    if(index != -1)
        cout<<"Element "<<a[index]<<" found at index: "<<index<<endl;
    else
        cout<<"Element not found"<<endl;

    return 0;
}
