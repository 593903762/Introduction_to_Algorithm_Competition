#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int a[maxn];

// 查找数组a[top]到a[end]之间的元素最大值
int max_idx(int a[], int top, int end)
{
    int max_value = a[top];
    for (int i = top + 1; i <= end; i++)
        if (max_value < a[i])
            max_value = a[i];
    return max_value;
}

int main()
{
    memset(a, 0, sizeof(a));
    int n;
    // 输入每一轮队列中任务的个数
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int top = 0, end = n - 1, focus, count = 0;
        scanf("%d", &focus);
        while (focus != top - 1)
        {
            if (a[top] != max_idx(a, top, end))
            {
                a[end + 1] = a[top];
                focus = (focus + end - top) % (end - top + 1);
                top++;
                end++;
                focus++;
            }
            else
            {
                count++;
                top++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

//======================================================================================
/*
new method
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int tasks[100];
    memset(tasks, 0, sizeof(tasks));
    int n, focus;
    scanf("%d", &n);
    scanf("%d", &focus);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tasks[i]);
    }

    int bigs = 0, equals = 0;
    int k = 10, index = -1; // k为比关注任务优先级大的所有任务中优先级最小的任务，index为其下标
    for (int i = 0; i < n; i++)
    {
        if (i == focus)
        {
            continue;
        }
        else
        {
            if (tasks[i] > tasks[focus])
            { // 优先级比关注任务大
                bigs++;
                if (tasks[i] <= k)
                {
                    k = tasks[i];
                    index = i;
                    equals = 0;
                }
            }
            else if (tasks[i] == tasks[focus])
            {
                if (index < focus && i < focus)
                { // 如果k在关注任务之前，只需要计算两者之间优先级等于focus的任务即可
                    equals++;
                }
                else if (index > focus)
                { // 如果k在关注任务之后，计算k之后所有优先级等于focus的任务
                    equals++;
                }
            }
        }
    }
    printf("%d\n", bigs + equals + 1);

    return 0;
}