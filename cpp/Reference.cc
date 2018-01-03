#include <iostream>

using namespace std;

/**
 * @license BSD-3
 * @author farwish <farwish@foxmail.com>
 */

// 传一个指针，对指针指向的值加1, 返回一个指针
int* f(int* x) {
    (*x)++;
    return x;
}

// 传一个参数的引用，直接加1，不需要解引用，返回一个引用
int& g(int& x) {
    x++;
    return x;
}

int z = 0;

// 返回值为引用，可以做左值，修改x
int& h() {
    return z;
}


int main()
{
    int x = 0;
    cout << "f(&x) = " << *f(&x) << endl; // 丑陋，但是显而易见

    int& y = x;
    cout << "g(y) = " << g(y) << endl;    // 干净，但是参数不明显，必须看原型才能知道参数能否被修改

    h() = 2;
    cout << "z = " << z << endl;

    return 0;
}

/*

f(&x) = 1
g(y) = 2
z = 2

*/
