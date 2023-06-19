#include <iostream>
using namespace std;


class A {
    public:
        virtual int fun() = 0;
        virtual void haha(*A);

};

class B : public A {
    public:
        int fun() {
            cout << "B!" << endl;
            return 0;
        }
};

class C : public A {
    public:
        int fun() {
            cout << "C" << endl;
            return 0;
        }
};

void foo(A* ptr) {
    ptr->fun();
}

int main() {
    B b1;
    foo(&b1);
    return 0;
}
