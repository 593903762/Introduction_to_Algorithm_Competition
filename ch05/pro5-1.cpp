#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int max_row = 100;
vector<string> codes[max_row];


// 位字符串s填充空格，直至其长度为M
void padding(string &s, int M)
{
    int len = s.length();
    for (int i = 0; i < M - len; i++)
        s.append(" ");
}

int main()
{
    string line;
    int cur = 0;
    // 加上 '#' 用于测试
    while (getline(cin, line) && line != "#")
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
            codes[cur].push_back(word);
        cur++;
    }

    // 确定最长vector的长度
    int max_col = 0;
    for (int r = 0; r < cur; r++)
    {
        if (max_col < codes[r].size())
            max_col = codes[r].size();
    }

    for (int c = 0; c < max_col; c++)
    {
        int M = 0;
        for (int r = 0; r < cur; r++)
        {
            if (codes[r].size() >= c + 1)
            {
                M = max(M, (int)codes[r][c].length());
            }
        }
        for (int r = 0; r < cur; r++)
        {
            // 为本列不足长度M的单词填充空格，使其长度为M
            if (codes[r].size() >= c + 1)
            {
                padding(codes[r][c], M);
            }
        }
    }

    for (int r = 0; r < cur; r++)
    {
        for (int c = 0; c < codes[r].size(); c++)
        {
            cout << codes[r][c] << " ";
        }
        printf("\n");
    }

    return 0;
}