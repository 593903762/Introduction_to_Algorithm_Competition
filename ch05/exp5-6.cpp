#include <cstdio>
#include <map>
#include <queue>

using namespace std;

/*
queue的使用
q.front(); q.pop(); q.push(x);
*/

const int maxn = 1010;

int main()
{
    int t, kase = 0;
    while (scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);

        // record the team of each person
        map<int, int> team;
        for (int i = 0; i < t; i++)
        {
            int n, x;
            scanf("%d", &n);
            while (n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        // 整体队列与各个团队的子队列
        queue<int> q, q2[maxn];
        while (true)
        {
            int x;
            char cmd[10];
            scanf("%s", cmd);
            if (cmd[0] == 'S')
                break;
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if (q2[t].empty())
                    q.pop();
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d", &x);
                int t = team[x];
                if (q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}