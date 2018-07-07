//
// Created by ninja on 7/6/18.
//

#include <iostream>

using namespace std;

int binary_search(int n, int a[], int k) {
    int low=0, high=n-1, mid;

    do {
        mid = (low+high)/2;
        if(a[mid] > k)
            high = mid - 1;
        else if(a[mid] < k)
            low = mid + 1;
        else
            return mid;
    } while (low <= high);

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

    int index = binary_search(n, a, k);

    if(index != -1)
        cout<<"Element "<<a[index]<<" found at index: "<<index<<endl;
    else
        cout<<"Element not found"<<endl;

    return 0;
}