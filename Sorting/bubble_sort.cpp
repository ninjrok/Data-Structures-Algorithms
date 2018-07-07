//
// Created by ninja on 7/7/18.
//

#include<iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n+1], temp, n_swaps=0;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                n_swaps++;
            }

    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Number of swaps= "<<n_swaps<<endl;

    return 0;
}