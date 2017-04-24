#include <stdio.h>
#include <time.h>

/**
 * gcc -Wl, -M time.c 
 * 产生链接器映像到标准输出.
 *
 * gcc -Wl, -M time.c > time.linker.map
 * 产生链接器映像(link map)到文件.
 *
 * nm [a.out]
 * 列出函数库所包含的函数.
 * 
 * @farwish
 */
int
main()
{
    time_t t;
    time_t ret;
    char *r;
    struct tm *tms;

    ret = time(&t);

    tms = localtime(&ret);

    printf("当前时间：%d-%d-%d %d:%d:%d\n", 
            tms->tm_year + 1900,
            tms->tm_mon + 1,
            tms->tm_mday,
            tms->tm_hour,
            tms->tm_min,
            tms->tm_sec
            );

    return 0;
}
