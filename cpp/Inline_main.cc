#include <iostream>
#include "Inline.h"

using namespace std;

int main()
{
    Rectangle r(0, 0);

    cout << "getWidth() " << r.getWidth() << endl;
    cout << "getHeight() " << r.getHeight() << endl;

    r.setWidth(1);
    r.setHeight(1);

    cout << "after set, getWidth() " << r.getWidth() << endl;
    cout << "after set, getHeight() " << r.getHeight() << endl;

    return 0;
}
