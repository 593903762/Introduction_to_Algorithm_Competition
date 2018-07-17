#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1010;
char s[maxn];
bool failed; // 输入数据不可以构建一棵树

// 定义树结点
struct Node
{
    bool have_value;
    int v;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {}
};

// 树根的指针
Node *root;

// 为新的树结点分配存储空间
Node *new_node()
{
    return new Node();
}

// 消除内存泄漏，但是会产生内存碎片
void remove_tree(Node *u)
{
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

// 根据输入的字符串位置信息将结点添加至树中正确的位置
void add_node(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = new_node();
            u = u->left;
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = new_node();
            u = u->right;
        }
    }
    // 重复赋值，意味着输入信息有误，设置failed信号
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
}

// 从输入的字符序列中中读取信息并生成一棵树
bool read_input()
{
    failed = false;
    remove_tree(root);
    root = new_node();
    for (;;)
    {
        // 每次读入一个结点的信息，由括号、数字以及位置组成
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s, "()"))
            break;
        int v;
        // 从s[1]开始的地址往后读，读出一个整型变量数值
        sscanf(&s[1], "%d", &v);
        // 逗号字符的下一个字符的地址开始的字符子串
        add_node(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    ans.clear();
    q.push(root);
    // 借助一个队列即可实现广度优先遍历：每次弹出队首元素之后依次将左右子结点入队
    while (!q.empty())
    {
        Node *u = q.front();
        q.pop();
        if (!u->have_value)
            return false;
        ans.push_back(u->v);
        if (u->left != NULL)
            q.push(u->left);
        if (u->right != NULL)
            q.push(u->right);
    }
    return true;
}

int main()
{
    if (read_input())
    {
        if (failed)
            printf("-1\n");
        else
        {
            vector<int> ans;
            if (bfs(ans))
            {
                vector<int>::iterator it = ans.begin();
                while (it != ans.end())
                {
                    printf("%d ", *it);
                    it++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}