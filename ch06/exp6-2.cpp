#include <cstdio>
#include <stack>

using namespace std;
const int maxn = 1010;

int n, target[maxn];

/*
判断入栈和出栈顺序，典型题目！
*/

int main()
{
    while (scanf("%d", &n) == 1)
    {
        stack<int> s;
        int A = 1, B = 1;
        for (int i = 1; i <= n; i++)
            scanf("%d", &target[i]);
        int ok = 1;
        while (B <= n)
        {
            // 刚进栈的，就立即出栈
            if (A == target[B])
            {
                A++;
                B++;
            }
            // 位于中转站栈首的出栈
            else if (!s.empty() && s.top() == target[B])
            {
                s.pop();
                B++;
            }
            // 出栈只有上述两种可能，要是还没结束，就把当前进来的入栈(或许后面用到)
            else if (A <= n)
                s.push(A++);
            // 没有备用的可以用了，说明该顺序有问题
            else
            {
                ok = 0;
                break;
            }
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}