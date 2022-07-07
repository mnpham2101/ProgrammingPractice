#include<iostream>
using namespace std;


class B {
public:
    B(int x) : myVar(x) {};
private:
    int myVar;
    friend class A;                                 // A is a friend of b and and can access B directly. B is not a friend of A!!!! B cannot access private of A.
};

class A {
public:
    int getMyVar(B& b) { return b.myVar; };         // direct access to private variable without get/set function
};

int main() {
    B b(5);
    //b.myVar;                                      // normally this is not allowable
    A a;
    cout << a.getMyVar(b) << endl;
}