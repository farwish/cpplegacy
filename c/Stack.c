#include <stdio.h>

/**
 * 整型 "栈" 数据的表示及操作
 *
 * @farwish
 */

#define STACK_SIZE 100

typedef struct {
    int idx;
    int buffer[STACK_SIZE];
} Stack;

// 初始化
void init(Stack *st);
// 加入. 0 success; -1 fail
int push(Stack *st, int number);
// 弹出. 0 success; -1 fail
int pop(Stack *st, int* retval);
// 输出所有
void list(Stack *st);

int
main(void)
{
    Stack st;
    int retval = 0;

    init(&st);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);

    list(&st);

    pop(&st, &retval);

    printf("pop value is %d\n", retval);

    list(&st);

    return 0;
}

void
init(Stack *st)
{
    int j = 0;
    st->idx = -1;

    // 循环初始化数组值
    for (j; j < STACK_SIZE; j++) {
        st->buffer[j] = 0;
    }
}

int
push(Stack *st, int number)
{
    if (st->idx >= STACK_SIZE - 1) {
        printf("stack is full.\n");
        return -1;
    } 

    st->idx++;
    st->buffer[st->idx] = number;

    return 0;
}

int
pop(Stack *st, int *retval)
{
    if (st->idx < 0) {
        printf("stack is empty.\n");
        return -1;
    }

    *retval = st->buffer[st->idx];
    st->buffer[st->idx] = 0;
    st->idx--;

    return 0;
}

void
list(Stack *st)
{
    int i = 0;
    for (i; i <= st->idx; i++) {
        printf("Stack.buffer[%d] = %d\n", i, st->buffer[i]);
    }
}
