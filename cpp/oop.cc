#include <iostream>

using namespace std;

/**
 * 'this' address equals to class object address
 *  but not equals to method first argument address.
 *
 * @author farwish
 */
class Fruit
{
    public:
            // 构造函数必须声明为 public 才能定义
            Fruit(int i, int j);
            void peel(), juice(void *p);

    private: int weight, size;
};

Fruit::Fruit(int i, int j)
{
    // 两种方式
    this->weight = i;
    size = j;
}

void Fruit::peel()
{
    cout << "this ptr = " << this << endl;

    // 两种方式
    this->weight--;
    weight--;

    cout << "this->weight = " << this->weight << ", weight = " << weight << ", size = " << size << endl;
}

// the first argument is 'this' pointer.
void Fruit::juice(void *p)
{
    cout << "juice first argument ptr = " << p << endl;
}

int main()
{
    Fruit apple(10, 5);
    void *p;

    cout << "apple ptr = " << &apple << endl;

    apple.juice(p);

    apple.peel();
}
