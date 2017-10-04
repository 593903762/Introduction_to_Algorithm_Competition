#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char s1[200], s2[200];
    while (scanf("%s%s", s1, s2) == 2)
    {
        int n = strlen(s1);
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (int i = 0; i < n; i++)
            cnt1[s1[i] - 'A']++;
        for (int i = 0; i < n; i++)
            cnt2[s2[i] - 'A']++;
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        int ok = 1;
        for (int i = 0; i < 26; i++)
            if (cnt1[i] != cnt2[i])
                ok = 0;
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

/*强行使用map和vector的版本
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
#define maxn 80

int main() {
    while(cin.peek() != EOF) {
        map<char, int> cnt1, cnt2;
        for(char c = 'A'; c <= 'Z'; c++) {
            cnt1[c] = cnt2[c] = 0;
        }
        char s1[maxn], s2[maxn];
        char x;
        scanf("%s", s1);
        stringstream ss(s1);
        while(ss >> x) cnt1[x]++;
        scanf("%s", s2);
        stringstream ss2(s2);
        while(ss2 >> x) cnt2[x]++;

        vector<int> word1, word2;
        for(int i = 0; i < 26; i++) {
            word1.push_back(cnt1[char(i+65)]);
            word2.push_back(cnt2[char(i+65)]);
        }
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());


        for(int i = 0; i < 26; i++) {
            cout << word1[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < 26; i++) {
            cout << word2[i] << " ";
        }


        for (int i = 0; i < 26; i++)
        {
            if (word1[i] != word2[i])
            {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
    }
    return 0;
}
*/