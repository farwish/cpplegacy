#include <iostream>

using namespace std;

/**
 * @license BSD-3
 * @author farwish <farwish@foxmail.com>
 */
class A {

private:
    const int i;

public:

    A() : i(0) {
    }

    void f() {
        cout << "A::f()" << endl;
    }

    void f() const {
        cout << "A::f() const" << endl;
    }
};

int main()
{
    A a;
    a.f(); // A::f()

    const A a2;
    a2.f(); // A::f() const

    return 0;
}
