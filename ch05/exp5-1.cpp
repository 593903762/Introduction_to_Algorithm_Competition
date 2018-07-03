#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

/*
sort方法的运用
*/
int main() {
    int N, Q, x, a[maxn], kase = 0;
    while (scanf("%d%d", &N, &Q) == 2 && N) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        sort(a, a + N);
        while (Q--) {
            scanf("%d", &x);
            int p = lower_bound(a, a + N, x) - a;
            if (a[p] == x)
                printf("%d found at %d\n", x, p + 1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}