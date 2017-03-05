#include <stdio.h>
#include <unistd.h>

/**
 * get configuration infomation at run time.
 *  long sysconf(int name);
 *
 * get configuration values for file.
 *  long fpathconf(int fd, int name);
 *  long pathconf(char *path, int name);
 *
 * NOTE: 在shell中可以用 ulimit -a 查看这些值.
 *
 * @farwish
 */

int main(void)
{
    // 4096
    printf("每个实际用户ID的最大进程数(CHILD_MAX) = %ld\n", sysconf(_SC_CHILD_MAX));

    // 1024
    printf("每个进程最大打开文件数(OPEN_MAX) = %ld\n", sysconf(_SC_OPEN_MAX));

    return 0;
}
