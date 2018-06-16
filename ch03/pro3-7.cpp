#include <stdio.h>
#include <cstring>

#define maxm 55
#define maxn 1005
char DNA[maxm][maxn];
int nums[4][maxn];

int main()
{
    int m, n;
    char consensus[4] = {'A', 'C', 'G', 'T'};
    while (scanf("%d%d", &m, &n) == 2 && !(m == 0 && n == 0))
    {
        int distance = 0;
        memset(nums, 0, sizeof(nums));

        for (int i = 0; i < m; i++)
        {
            scanf("%s", DNA[i]);
        }
        printf("\nThe DNA consensus string is: ");
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                switch (DNA[i][j])
                {
                case 'A':
                    nums[0][j]++;
                    break;
                case 'C':
                    nums[1][j]++;
                    break;
                case 'G':
                    nums[2][j]++;
                    break;
                case 'T':
                    nums[3][j]++;
                    break;
                }
            }
            int best = nums[0][j], best_index = 0;
            for (int i = 1; i < 4; i++)
            {
                if (nums[i][j] > best)
                {
                    best = nums[i][j];
                    best_index = i;
                }
            }
            distance += m - nums[best_index][j];
            printf("%c", consensus[best_index]);
        }
        printf("\ndistance = %d\n", distance);
    }
    return 0;
}