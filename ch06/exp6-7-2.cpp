#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100010;

/**
 * 树结构的数组实现
 * */
int value[maxn], left[maxn], right[maxn];
bool have_value[maxn];
const int root = 1;

int cnt;     // 树结点计数器
bool failed; // 建树失败(1.有至少一个结点没有value; 2.有至少一个结点有多个value)

void new_tree()
{
    left[root] = right[root] = 0;
    have_value[root] = false;
    cnt = root;
}

int new_node()
{
    int u = ++cnt;
    left[u] = right[u] = 0;
    have_value[u] = false;
    return u;
}

void add_node(int v, char *s)
{
    int n = strlen(s);
    int it = root;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
        {
            if (!left[it])
                left[it] = new_node();
            it = left[it];
        }
        else if (s[i] == 'R')
        {
            if (!right[it])
                right[it] = new_node();
            it = right[it];
        }
    if (have_value[it])
        failed = true;
    value[it] = v;
    have_value[it] = true;
}

char s[maxn]; // 输入字符
bool read_input()
{
    failed = false;
    new_tree();
    for (;;)
    {
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s, "()"))
            break;
        int v;
        sscanf(&s[1], "%d", &v);
        add_node(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<int> q;
    ans.clear();
    q.push(root);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!have_value[u])
            return false;
        ans.push_back(value[u]);
        if (left[u])
            q.push(left[u]);
        if (right[u])
            q.push(right[u]);
    }
    return true;
}

int main()
{
    vector<int> ans;
    while (read_input())
    {
        if (!bfs(ans))
            failed = true;
        if (failed)
            printf("-1\n");
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (i != 0)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}