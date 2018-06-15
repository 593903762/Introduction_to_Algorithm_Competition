/* 此方法只适用于'每一个原子后跟着的数字为个位数'的情形 */
#include <stdio.h>
#include <cstring>
#include <cctype>

#define maxn 85

int main()
{
    char s[maxn];
    while (scanf("%s", s) == 1)
    {
        int nums[4] = {0, 0, 0, 0};
        int len = strlen(s), index;
        double sum = 0.0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(s[i]))
            {
                if (s[i] == 'C')
                    index = 0;
                else if (s[i] == 'H')
                    index = 1;
                else if (s[i] == 'O')
                    index = 2;
                else
                    index = 3;
                nums[index]++;
            }
            else
                nums[index] += s[i] - '0' - 1;
        }
        sum += 12.01 * nums[0] + 1.008 * nums[1] +
               16.00 * nums[2] +
               14.01 * nums[3];
        printf("%.3fg/mol\n", sum);
    }
    return 0;
}