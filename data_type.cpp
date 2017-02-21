#include <iostream>
#include <typeinfo>
using namespace std;

/**
 * date type.
 *
 * @farwish
 */
int main(void)
{
        cout << "sizeof(short int) = " << sizeof(short int) << endl;
        cout << "sizeof(int) = " << sizeof(int) << endl;
        cout << "sizeof(123456789) = " << sizeof(123456789) << endl;
        cout << "sizeof(1) = " << sizeof(1) << endl;
        cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << endl;
        cout << "sizeof(long int) = " << sizeof(long int) << endl;

        cout << "sizeof(float) = " << sizeof(float) << endl;
        cout << "sizeof(double) = " << sizeof(double) << endl;
        cout << "sizeof(long double) = " << sizeof(long double) << endl;

        cout << "sizeof(char) = " << sizeof(char) << endl;
        cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;

        cout << "sizeof('c') = " << sizeof('c') << endl;
        cout << "sizeof(\"b\") = " << sizeof("b") << endl;
        cout << "sizeof(\"bbbbb\") = " << sizeof("bbbbb") << endl;
        cout << "sizeof(\"你\") = " << sizeof("你") << endl;

        char a[] = "aaaaa";
        int count = sizeof(a)/sizeof(a[0]);

        cout << "count a[]=\"aaaaa\" is " << count << endl;

        for (int i = 0; i < count; i++)
        {
                cout << "a[i] = " << a[i] << endl;
        }

        cout << "12.3*(3/5)   type is " << typeid(12.3*(3/5)).name() << " , value is " << 12.3*(3/5) << endl;
        cout << "'a'+10*5.2   type is " << typeid('a'+10*5.2).name() << " , value is " << 'a'+10*5.2 << endl;
        cout << "12U+3.0F*24L type is " << typeid(12U+3.0F*24L).name() << " , value is " << 12U+3.0F*24L << endl;

        cout << "\n字符数组(a[])指针输出的例外, 不是地址，而是字符串;\n"
             << "输出指针需要强制类型转换(void *)a\n" << endl;
        cout << "字符数组     a = " << a << endl;
        cout << "字符数组指针 a = " << (void *)a << endl;
        cout << "字符数组值  *a = " << *a << endl;

        return 0;
}

