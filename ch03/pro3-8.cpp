#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) == 2 && a)
    {
        int iter_len = 0;
        vector<int> as, out;
        printf("%d.", a / b);
        a %= b;
        while (!count(as.begin(), as.end(), a))
        {
            as.push_back(a);
            out.push_back(a * 10 / b);
            a = a * 10 % b;
            iter_len++;
        }
        int pos = 0;
        for (vector<int>::iterator iter = as.begin(); iter < as.end(); iter++)
        {
            if (*iter == a)
                break;
            pos++;
        }
        for (vector<int>::iterator iter = out.begin(); iter < out.end(); iter++)
        {
            if (iter - out.begin() == pos)
                printf("(");
            printf("%d", *iter);
        }
        printf(")\nrecurring period length: %d\n", iter_len);
    }
    return 0;
}