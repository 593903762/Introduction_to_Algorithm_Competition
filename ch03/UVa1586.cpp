#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>
#include <sstream> //ʹ��stringstream��Ҫ�������ͷ�ļ�

using namespace std;

#define maxn 20
char s[maxn];
float q[4] = {12.01, 1.008, 16.00, 14.01};
int p[4] = {0, 0, 0, 0};

//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�
template <class Type>
Type stringToNum(const string &str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

int main()
{
    while (scanf("%s", s) == 1)
    {
        string str = s;
        int num = 0;
        int n = strlen(s);
        for (int i = 0; i < n;)
        {
            if (isalpha(s[i]))
            {
                int j = i + 1;
                while (!isalpha(s[j]))
                    j += 1;
                if (j != i + 1)
                {
                    string tmp = str.substr(i + 1, j - 1); //���������⣬�����ȷ��ȡ�Ӵ���
                    num = stringToNum<int>(tmp);
                }
                switch (s[i])
                {
                case 'C':
                    p[0] += num;
                    break;
                case 'H':
                    p[1] += num;
                    break;
                case 'N':
                    p[2] += num;
                    break;
                case 'O':
                    p[3] += num;
                    break;
                }
                i = j;
            }
        }
        float sum = 0.0;
        for (int i = 0; i < 4; i++)
        {
            printf("%d ", p[i]);
            sum += q[i] * p[i];
        }
        printf("Mass = %dg/mol\n", sum);
    }
    return 0;
}