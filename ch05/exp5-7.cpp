#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
 * 优先级队列：最先出队列的是优先级最高的元素，不一定在队首
 * pq.top(); pq.push(x); pq.pop();
 * 
 * priority_queue<int> pq;  越小的整数优先级越低
 * priority_queue<int, vector<int>, greater<int>> pq;
 * 
 * priority_queue<int, vector<int>, cmp> pq;
 * 自定义优先级：
 * struct cmp {
 *     bool operator () (const int a, const int b) const {
 *         // a的优先级比b小的时候返回true
 *         return a % 10 > b % 10;
 *     }
 * }
 */

typedef long long LL;
const int coef[3] = {2, 3, 5};

int main() {
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1; ; i++) {
        LL x = pq.top(); pq.pop();
        if (i == 1500) {
            cout << "The 1500'th uglt number is " << x << endl;
            break;
        }
        for (int j = 0; j < 3; j++) {
            LL x2 = x * coef[j];
            if (!s.count(x2)) {
                s.insert(x2); pq.push(x2);
            }
        }
    }
    return 0;
}