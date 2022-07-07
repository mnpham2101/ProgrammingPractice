#include<iostream>
using namespace std;

class B {                                                   // B must be declared before A
private:
    int myVar;
public:
    B(int x) { myVar = x; };
    int getMyVar() { return myVar; };
    int setMyVar(int x) { return myVar = x; };
};

class A {
public:
    A(B &b) : m_b ( b ) {};

    int setB(int x) { return m_b.setMyVar(x); };            // A can access and get B's private/protected variables/functions
    int callB() { return m_b.getMyVar(); };

private:
    B & m_b;            // A has a ref to B, A is associated with B; likewise, we can use pointers
};


int main() {
    B b(1);                             // B's myVar is set to 1
    A a(b);                             // ref of b is passed to A constructor => myVar = 1
    cout<<a.callB()<<endl;
    cout<<a.setB(8) << endl;            // return a can access and change myVar = 8
}