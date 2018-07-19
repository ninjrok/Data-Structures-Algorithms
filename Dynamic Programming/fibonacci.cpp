//
// Created by ninja on 7/19/18.
// Dynamic Programming with Memoization & Bottom-Up approaches
//

#include <iostream>
#include <map>

using namespace std;

map<int, int> fibonacciMemo;
int fibonacci_with_memoization(int n) {
    int f;
    if (fibonacciMemo.find(n) != fibonacciMemo.end())
        f = fibonacciMemo[n];
    if(n <= 2)
        f = 1;
    else
        f = fibonacci_with_memoization(n-1) + fibonacci_with_memoization(n-2);

    fibonacciMemo[n] = f;

    return f;
}

int fibonacci_bottom_up(int n) {
    map<int,int> fibNumbers;
    int f;
    for(int i=1;i<=n;i++) {
        if(i <= 2)
            f = 1;
        else
            f = fibNumbers[i-1] + fibNumbers[i-2];
        fibNumbers[i] = f;
    }

    return fibNumbers[n];
}

int main() {
    int n, *a;
    cout<<"Enter n: ";
    cin>>n;

    // Memoization
    int nthFibonacci = fibonacci_with_memoization(n);
    cout<<"All fibonacci numbers from memo: \n";
    for (auto it = fibonacciMemo.begin(); it != fibonacciMemo.end() ; ++it) {
        cout<<it->first<<": "<<it->second<<endl;
    }
    cout<<"The nth Fibonacci number calculated by the memoization approach is: "<<nthFibonacci<<endl;

    // Bottom-Up Approach
    nthFibonacci = fibonacci_bottom_up(n);
    cout<<"The nth Fibonacci number calculated by the bottom-up approach is: "<<nthFibonacci<<endl;

    return 0;
}
