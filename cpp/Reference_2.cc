#include <iostream>

/**
 * @license BSD-3
 * @author farwish <farwish@foxmail.com>
 */
using namespace std;

// declaration and defination 应该放在头文件中，此处仅做演示
class X {
public:
    int& i;
    X(int& a);
};

class Y {
public:
    int j;
    Y();
    void set(int a) {
        j = a;
        cout << "Y::set(a), Y.j = " << j << endl;
    }
};

X::X(int& a) : i(a) {
    cout << "X::X(int&)" << endl;
}

Y::Y() : j(0) {
    cout << "Y::Y(int)" << endl;
}

const int SIZE = 32;
double arr[SIZE];
double& subscript(const int i) {
    return arr[i]; // 可以返回全局变量的引用
}

// 返回一个对象，将来可以操作这个对象，包括更改
Y f() {
    Y y;
    return y;
}

int main() {
    int a = 10;
    X x(a);
    cout << "x.i = " << x.i << endl;

    for (int i = 0; i < SIZE; i++) {
        arr[i] = i * 0.5;
    }
    double value = subscript(12); // 返回的是reference，但赋给一个普通变量，这相当于把值赋给了变量
    subscript(3) = 34.5;          // 把数组第三个值改为了34.5
    cout << "arr[3] = " << arr[3] << endl;

    cout << "f().j = " << f().j << endl;
    f().set(2);
    cout << "f().j = " << f().j << endl; // f() 返回的是临时对象，值没有改变

    // 不能对函数返回的对象做左值
    // f().j = 10; // error: using temporary as lvalue [-fpermissive]

    return 0;
}

/*

X::X(int&)
x.i = 10

arr[3] = 34.5

Y::Y(int)
f().j = 0
Y::Y(int)
Y::set(a), Y.j = 2
Y::Y(int)
f().j = 0

*/
