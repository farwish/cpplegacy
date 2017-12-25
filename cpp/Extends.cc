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

class AA {
    private:
        int i;

    public:
        AA(int ii) : i(ii) {
            cout << "AA:AA() --->i = " << i << endl;
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

class BB : public AA {
    public:
        // 当实例化子类时，父类的构造函数会先被调用，当父类没有默认构造函数时，必须在子类中用 initializer list 对父类成员初始化
        BB() : AA(0) {
        }
};

int main()
{
    B b;
    BB bb;
    b.print();
    b.set(1);
    b.print();

    b.p();

    // error, j 是受保护的
    // cout << "in main b.j = " << b.j << endl;
}

/* Output:

A::A()
AA:AA() --->i = 0
A::A() ----> i = 0
A::A() ----> i = 1
B::p() ----> j = 1
A::~A()

*/
