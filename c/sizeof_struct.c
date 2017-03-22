#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct points {
    int x;
    double y;
    char z;
};

/**
 * sizeof struct.
 *
 * @farwish
 */
int main(void)
{
    struct date today;
    struct date tomorrow;
    struct points p;

    today = (struct date){2,21,2017};
//  tomorrow = (struct date){2,22,2017};

    printf("sizeof(today)   = %ld\n", sizeof(today));
    printf("sizeof(tomorrow)= %ld\n", sizeof(tomorrow));

    printf("&(today.month)  = %p\n", &today.month);
    printf("&(today.day)    = %p\n", &(today.day));
    printf("&(today.year)   = %p\n", &(today.year));

    printf("sizeof(p)       = %ld\n", sizeof(p));
    printf("sizeof(int)     = %ld\n", sizeof(int));
    printf("sizeof(double)  = %ld\n", sizeof(double));
    printf("sizeof(char)    = %ld\n", sizeof(char));

    printf("&(p.x)          = %p\n", &(p.x));
    printf("&(p.y)          = %p\n", &(p.y));
    printf("&(p.z)          = %p\n", &(p.z));

    return 0;
}
