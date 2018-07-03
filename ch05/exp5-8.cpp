#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int max_col = 60;
const int maxn = 105;
string filename[maxn];

// 输出长度为s的字符串，当s长度不足len时，补充输出extra字符
// 确保len >= s.length()
void print(const string &s, int len, char extra)
{
    cout << s;
    for (int i = 0; i < len - s.length(); i +)
        cout << extra;
}

int main()
{
    int n;
    while (cin >> n)
    {
        int M = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> filename[i];
            M = max(M, (int)filename[i].length());
        }

        int cols = (max_col - M) / (M + 2) + 1;
        // 行数的确定值得反复琢磨(常用手法)
        int rows = (n - 1) / cols + 1;

        print("", max_col, '-');
        printf("\n");

        sort(filename, filename + n);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                // 此处乘rows记为按列优先的顺序，乘cols则是按行优先的顺序
                int idx = c * rows + r;
                if (idx < n)
                    print(filename[idx], c == cols - 1 ? M : M + 2, ' ');
            }
            printf("\n");
        }
    }
    return 0;
}