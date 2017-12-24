#include <iostream>

/**
 * @license Apache-2.0
 * @author farwish <farwish@foxmail.com>
 */
using namespace std;

class A {
    private:
        int i;

    protected:
        int j;

    public:
        A(): i(0), j(0) {
            cout << "A::A()" << endl;
        }

        ~A() {
            cout << "A::~A()" << endl;
        }

        void print() {
            cout << "A::A() ----> i = " << i << endl;
        }

        void set(int x) {
            i = x;
        }
};

/**
 * 继承
 */
class B : public A {
    public:
        void p() {
            // error, i 是父类私有的
            // x = 2;

            // 子类可以访问受保护的
            j = 1;
            cout << "B::p() ----> j = " << j << endl;
        }
};

int main()
{
    B b;
    b.print();
    b.set(1);
    b.print();

    b.p();

    // error, j 是受保护的
    // cout << "in main b.j = " << b.j << endl;
}

/* Output:

A::A()
A::A() ----> i = 0
A::A() ----> i = 1
B::p() ----> j = 1
A::~A()

*/
