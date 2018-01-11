#include <iostream>

using namespace std;

/**
 * Static members.
 *
 */
class A
{
public:
    A() { cout << i << endl; }
    void print() { cout << i << endl; }
    void set(int i) { this->i = i; }
    // 静态函数不能访问非静态成员变量
    static void say(int j) { cout << j << i << endl; }
private:
    int k;
    static int i;
};

// 静态成员变量的初始化，必须以双引号的方式初始化
int A::i = 10;

int main()
{
    A a,b;

    a.set(20);
    a.print();
    b.print();


    // 访问静态成员函数也有两种方式
    a.say(0);
    A::say(0);

    // 受访问控制限制，无法访问.
    // cout << A::i << endl;

    return 0;
}

/*

   10
   10
   20
   20
   020
   020

*/
