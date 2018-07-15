//
// Created by ninja on 7/13/18.
//

#include <iostream>

using namespace std;

class Foo {
    int i;
    public:
        Foo() {
            cout<<"Foo without args!\n";
        }

        Foo(int value) {
            i = value;
            cout<<"Foo initialized with i= "<<value<<endl;
        }
};


class Bar: private Foo {
    public:
        Bar(): Foo() {
            cout<<"Bar initialized with foo. No agts.\n";
        }

        Bar(int value_for_foo): Foo(value_for_foo) {
            Bar();
            cout<<"Bar initialized with agt= "<<value_for_foo<<endl;
        }
};


int main() {

    Bar bar = Bar(10);

    return 0;
}