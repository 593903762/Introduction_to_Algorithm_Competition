#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    queue<int> q;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 1; i <= n; i++)
            q.push(i);
        printf("Thrown away cards: ");
        while (q.size() > 2)
        {
            int card1 = q.front();
            q.pop();
            int card2 = q.front();
            q.pop();
            q.push(card2);
            printf("%d ", card1);
        }
        // 只剩下两张牌的时候
        int above = q.front();
        q.pop();
        int below = q.front();
        printf("%d\nThe last card: %d", above, below);
    }
    return 0;
}