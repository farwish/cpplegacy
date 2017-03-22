#include <stdio.h>
#include <setjmp.h>

void first_call(void);
void second_call(void);
void third_call(void);

// int setjmp(jmp_buf env);             
//      save stack context for nonlocal goto
//
// void longjmp(jmp_buf env, int val);  
//      nonlocal jump to a saved stack context

/**
 * 非局部goto - setjmp, longjmp
 *
 * @farwish
 */

// 其余函数中要使用，必须为全局变量.
jmp_buf jmpbufenv;

int
main(void)
{
    int autoval;

    // return  0  if  returning  directly
    // and  nonzero  when  returning  from longjmp(3) 
    // or siglongjmp(3) using the saved context.
    if ( setjmp(jmpbufenv) != 0 ) {
        printf("error occurred.\n");
        return 1;
    } else {
        first_call();
    }

    return 0;
}

void
first_call(void)
{
    printf("first call.\n");

    second_call();
}

void
second_call(void)
{
    if ("error") {
        // 模拟遇到error, longjmp 设置第二个变量为非0
        // 造成main中 setjmp 的返回, 这次返回值是 longjmp 第二个参数.
        longjmp(jmpbufenv, 1);
    }

    printf("second call.\n");

    third_call();
}

void
third_call(void)
{
    printf("third call.\n");
}
