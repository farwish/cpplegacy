#include <iostream>
#include <string>

using namespace std;

static int objectCount = 0;

class HowMany {
public:
    HowMany() {
        objectCount++;
        print("HowMany()");
    }
    HowMany(int i) {
        objectCount++;
        print("HowMany(int i)");
    }
    //HowMany(const HowMany& y) {
    //    objectCount++;
    //    print("HowMany(const HowMany& y)");
    //}
    void print(const string& msg = "") {
        if (msg.size() != 0) {
            cout << msg << endl;
        }
        cout << "objectCount = " << objectCount << endl;
    }
    ~HowMany() {
        objectCount--;
        print("~HowMany()");
    }
};

HowMany f(HowMany x) {
    cout << "begin of f" << endl;

    x.print("x argument inside f()");

    cout << "end of f" << endl;

    return x;
}

int main()
{
    /*
    HowMany()
    objectCount = 1
    h.print
    objectCount = 1
    */
    HowMany h;
    h.print("h.print");

    /*
    begin of f
    x argument inside f()
    objectCount = 1
    end of f
    ~HowMany()
    objectCount = 0
    */
    HowMany h2 = f(h);

    /*
    after call f()
    objectCount = 0
    ~HowMany()
    objectCount = -1
    ~HowMany()
    objectCount = -2
    */
    h.print("after call f()");

    /*
    =======
    HowMany(int i)
    objectCount = 1
    =======
    */
    cout << "=======" << endl;
    HowMany h3 = 10;
    cout << "=======" << endl;
}

// 会什么在调用f(h)和初始化h2之后，没有调用类的构造函数？
// 关键在于 c++ 中，HowMany m(10) 与 HowMany m = 10 是等价的。
// 所以当 HowMany h2 = h 或 HowMany h2 = f(h) 实际是调用了不存在的构造函数 HowMany(HowMany x) 来初始化。
//     一般不直接传对象值，而是const的Reference，HowMany(const HowMany& x)，这样形式的构造函数叫 拷贝构造。
//     拷贝构造的唯一形式：T::T(const T&);
//     如果我们没有提供拷贝构造，而又使用自己的对象进行对象初始化，c++提供默认的拷贝构造，进行成员变量的拷贝。
// 上面加了参数为对象的构造函数之后，objectCount 就等于0了。
//
// 拷贝构造什么时候被调用？
// 1.用对象进行初始化时，Person p = p1 或 Person p(p1)，这两种写法相同，注意它不是 assignment 而是 initialization。
// 2.调用一个函数，函数的参数是一个对象时，void func(Person p);
// 3.用返回对象的函数返回值进行初始化。
//
// Construction vs Assignment
// 每个对象只能构造一次，每个对象应该被析构一次，
// 对象一旦被构造，它可以是被赋值的目标，前头有类型就是 initialization，没有类型就是 assignment.
//
// Copy constructor guidelines
// 写一个类就先写三个函数 default constructor, virtual distructor, copy constructor。
// 如果确实不需要拷贝构造，那么就声明为私有。
