#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void
charoutput(char *s)
{
    char c;

    sleep(1);
    setbuf(stdout, NULL);

    for ( c; (c = *s++) != 0; ) {
        putc((int)c, stdout);
    }
}

/**
 * 父子进程的竞争条件.
 *
 * （每次运行输出可能不一样.）
 *
 * @farwish
 */
int main(void)
{
    pid_t pid;

    printf("start.\n");

    if ( (pid = fork()) < 0 )
    {
        printf("fork error\n");
    } 
    else if ( pid == 0 )  // child
    { 
        charoutput("inChild\n");
    } 
    else // parent
    { 
        charoutput("inParent\n");
    }

    printf("DONE.\n");

    return 0;
}
