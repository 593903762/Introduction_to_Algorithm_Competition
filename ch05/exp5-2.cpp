#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

/*
vector的运用
v.push_back(x); v.resize(n); v.size()
*/

const int maxn = 30;
vector<int> pile[maxn];
int n;

// 找到木块a所在的堆以及在该堆的高度
void find_block(int a, int &p, int &h)
{
    for (p = 0; p < n; p++)
    {
        for (h = 0; h < pile[p].size(); h++)
        {
            if (a == pile[p][h])
                return;
        }
    }
}

// 归位第p个堆高度为h的木块上方所有的木块 (即安置到对应堆的上方)
void clear_above(int p, int h)
{
    for (int i = h + 1; i < pile[p].size(); i++)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

// 将第p个堆高度为h及上方所有的木块整体放置到p2堆的顶部
void pile_onto(int p, int h, int p2)
{
    for (int i = h; i < pile[p].size(); i++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < pile[i].size(); j++)
            printf(" %d", pile[i][j]);
        printf("\n");
    }
}

int main()
{
    int a, b;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; i++)
        pile[i].push_back(i);
    while (cin >> s1 && s1 != "quit")
    {
        cin >> a >> s2 >> b;
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
        if (pa == pb)
            continue;
        if (s2 == "onto")
            clear_above(pb, hb);
        if (s1 == "move")
            clear_above(pa, ha);
        pile_onto(pa, ha, pb);
    }
    print();
    return 0;
}