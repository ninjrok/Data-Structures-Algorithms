//
// Created by ninja on 7/7/18.
//

#include<iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n + 1], temp, n_swaps = 0;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; j++) {
            if(a[j] < a[i]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                n_swaps++;
            }
        }
    }

    cout<<"Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<" ";
    }

    cout<<endl<<"Number of swaps= "<<n_swaps<<endl;

    return 0;
}