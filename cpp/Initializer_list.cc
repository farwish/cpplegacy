#include <iostream>

/**
 * 初始化列表 && 对象组合
 *
 * @license Apache
 * @author farwish <farwish@foxmail.com>
 */
using namespace std;

class A {
    private:
        int i;
    public:
        A(int i) : i(i) {
            // 由于变量作用范围是就近原则，所以单独的 i 就表示参数，如果要表示成员变量，用 this 指针指向它
            cout << "A::A(i) ---> this->i = " << this->i << endl;
        }
};

/**
 * 初始化 vs 构造函数内赋值
 *
 * 初始化列表(推荐):
 * 可以初始化任何类型的数据, 不管是不是普通类型，都建议用
 * 不再需要在构造器中赋值了,初始化列表比构造函数要早执行
 * 成员初始化次序取决于在类中的声明次序
 *
 * 当类成员有其它对象时，构造器内给对象赋值会触发成员对象的默认构造函数(无参数的)，如果成员对象没有默认构造函数编译报错。
 * 所以当有成员变量为对象这种场景下，要用initialer list.
 */
class Point {
private:
    const float x,y;
    A a; // 对象组合, 复用的一种
public:
    Point(float xx = 0.0, float yy = 0.0, int i = 1) : x(xx), y(yy), a(i) {
        cout << "Point::Point() --->  x = " << x << ", y = " << y << endl;
    }
    ~Point() {
        cout << "Point::~Point()" << endl;
    }
    void print();
};

void Point::print() {
}

int main()
{
    Point p;

    p.print();
}

/* Output:

A::A(i) ---> this->i = 1
Point::Point() --->  x = 0, y = 0
Point::~Point()

*/
