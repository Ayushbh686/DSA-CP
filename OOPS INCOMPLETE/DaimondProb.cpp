#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

class B : virtual public A {
public:
    void show() {
        cout << "Class B" << endl;
    }
};

class C : virtual public A {
public:
    void show() {
        cout << "Class C" << endl;
    }
};

class D : public B, public C {
public:
    // Overriding the show() method to resolve ambiguity
    void show() {
        cout << "Class D" << endl; 
        // Accessing A's show() method using the scope resolution operator
        A::show(); 
        // Demonstrating calls to B's and C's show() methods
        B::show();
        C::show();
    }
};

int main() {
    D obj;
    obj.show();       // This will call D's show() method
    obj.B::show();    // This will call B's show() method
    obj.C::show();    // This will call C's show() method

    // To call A's show() method, we have to specify the path
    obj.A::show();    // This calls A's show() method

    return 0;
}
