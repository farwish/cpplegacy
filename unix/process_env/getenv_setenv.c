#include <stdio.h>
#include <stdlib.h>

// char *getenv(const char *name);
// int setenv(const char *name, const char *value, int overwrite);
// int putenv(char *string);
// int unsetenv(const char *name);

int main(void)
{
    char *name = "HOME";

    printf("before setenv, HOME = %s\n", (char*)getenv(name));

    if ( setenv(name, "/home/www", 1) == 0 )
    {
        printf("after setenv, HOME = %s\n", (char*)getenv(name));
    }

    if ( unsetenv(name) == 0 )
    {
        printf("after unsetenv, HOME = %s\n", (char*)getenv(name));
    }

    char *another = "HOME=/www";
    if ( putenv(another) == 0 )
    {
        printf("after putenv, HOME = %s\n", (char*)getenv(name));
    }

    return 0;
}
