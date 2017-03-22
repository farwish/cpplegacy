#include <iostream>

using namespace std;

/**
 * 整型 "栈" 数据的表示及操作
 *
 * Cpp 实现.
 *
 * @farwish
 */

#define STACK_SIZE 100

// As C Language's Struct Data Type.
class Stack
{
    private:
    int idx;
    int buffer[STACK_SIZE];

    public:        
    Stack()
    {
        int j = 0;
        idx = -1;

        // 循环初始化数组值
        for (j; j < STACK_SIZE; j++) {
            buffer[j] = 0;
        }
    }

    bool push(int number)
    {
        if (idx > STACK_SIZE - 1) {
            cout << "stack is full." << endl;
            return false;
        } 
        buffer[++idx] = number;
        return true;
    }

    bool pop(int *retval)
    {
        if (idx < 0) {
            cout << "stack is empty." << endl;
            return false;
        }
        *retval = buffer[idx];
        buffer[idx] = 0;
        idx--;
        return true;
    }

    void list()
    {
        int i = 0;
        for (i; i <= idx; i++) {
            cout << "buffer[" << i << "] = " << buffer[i] << endl;
        }
    }
};

int
main(void)
{
    Stack st;
    int retval;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.list();

    st.pop(&retval);
    cout << "pop value is " << retval << endl;

    st.list();
}
