#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

namespace AlconHelper {
    int getMaxOrMin(int *arr, int count, bool getMax = 1)
    {
        int ret = arr[0];

        for (int i = 1; i <= count; i++)
        {
            if (getMax) {
                if (ret < arr[i]) {
                    ret = arr[i];
                }
            } else {
                if (ret > arr[i]) {
                    ret = arr[i];
                }
            }
        }

        return ret;
    }
}

/**
 * cout and printf.
 *
 * @farwish
 */
int main(void)
{
    const int total = 101;
    int i, x;
    int arr[total] = {0};

    printf("请输入0~100之间的连续整数:\n");

    scanf("%d", &x);

    while(x != -1) 
    {
        if (x >= 0 && x <= 100)
        {
            arr[x] = x;
        }
        scanf("%d", &x);
    }

    for (i = 0; i <= total; i++)
    {
        printf("i (%d) = %d\n", i, arr[i]);
    }
   
    // 求最大最小值:

    int getMax = 1;

    cout << "取最大值输入：1，取最小值输入：0" << endl;

    cin >> getMax;

    cout << AlconHelper::getMaxOrMin(arr, total, getMax) << endl;

    return 0;
}
