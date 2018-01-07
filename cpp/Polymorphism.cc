#include <iostream>

using namespace std;

/**
 * Polymorphism
 *
 * @license BSD-3
 * @author farwish <farwish@foxmail.com>
 */

class XYPos {

};

/**
 * virtual : 将来子类里，如果重写了名称和参数相同的成员函数，那么这两个函数就是有联系的。
 */
class Shape {
public:
    Shape() {}
    virtual ~Shape() { cout << "Shape::~Shape()" << endl;  }
    void move(const XYPos&) {}
    virtual void resize() {}
    virtual void render() {}
protected:
    XYPos center;
};

/**
 * 子类的 virtual 加不加都是 virtual，但是更明显。
 */
class Ellipse : public Shape {
public:
    Ellipse(float maj, float minr) {}
    ~Ellipse() { cout << "Ellipse::~Ellipse()" << endl;  }
    virtual void render() {
        cout << "Ellipse::render()" << endl;
    }
protected:
    float major_axis, minor_axis;
};

/**
 * Circle 是特殊的 Ellipse，并用 initialize list 初始化父类。
 */
class Circle : public Ellipse {
public:
    Circle(float radius) : Ellipse(radius, radius) {}
    ~Circle() { cout << "Circle::~Circle()" << endl; }
    virtual void render() {
        cout << "Circle::render()" << endl;
    }
};

/**
 * 通用函数，对任何 Shape 和其子类都通用。
 *
 * 动态绑定，调用的 render 运行时决定:
 *  p 有一个静态类型和动态类型，如果 p 的 render 函数是 virtual 的，是动态绑定，不是 virtual 则是静态绑定。
 *  所以动态绑定还是静态绑定取决于 render 函数，而不是对象p；如果我们调用的是 move 函数，那么就是静态绑定。
 */
void render(Shape* p)
{
    p->render();
}

int main()
{
    Ellipse ell(10, 20);
    ell.render();       // 调用自己的render

    Circle circ(40);
    circ.render();      // 调用自己的render

    render(&ell);       // Upcast, 把ell当成Shape对象看待；调用了 Ellipse 类对象的 render

    render(&circ);      // Upcast


    Shape* p = new Ellipse(100.0, 110.0);
    delete p;

    return 0;
}

/*
   # Shape的析构不是 virtual 时，delete p 时，只有 Shape 的析构会被调用，Ellipse 的不会调用。

   Ellipse::render()
   Circle::render()
   Ellipse::render()
   Circle::render()

   Shape::~Shape()

   Circle::~Circle()
   Ellipse::~Ellipse()
   Shape::~Shape()
   Ellipse::~Ellipse()
   Shape::~Shape()
*/

/*
   # Shape的析构是 virtual 时，delete p 时，会先调子类的析构，在调父类的析构。
   # 其它 OOP 默认就是 virtual 的，也就是动态绑定的，而C++默认是静态绑定的，动态绑定需要手动加 virtual。

   Ellipse::render()
   Circle::render()
   Ellipse::render()
   Circle::render()

   Ellipse::~Ellipse()
   Shape::~Shape()

   Circle::~Circle()
   Ellipse::~Ellipse()
   Shape::~Shape()
   Ellipse::~Ellipse()
   Shape::~Shape()

*/
