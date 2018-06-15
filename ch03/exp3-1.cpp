/* 关于字符串的处理 */
/*
0. scanf("%s", s);                  从标准输入中读取字符串并写入s，遇到空格、TAB会停下来
1. sprintf(buf, "%d%d%d%d%d", a, b, c, d, e);
2. strchr(char_array, char);
3. fgetc(fin);                      从打开的文件fin中读取一个字符，返回一个int值(if end of file, return EOF)
4. getchar() == fgetc(stdin);
5. fgets(buf, maxn, fin);           遇到\n停止，可以读取完整的一行(不超过maxn-1个字符)放到buf中
6. gets(s);                         存在内存漏洞
*/
#include <stdio.h>

int main()
{
    int c, flag = 1;
    while ((c == getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", flag ? "“" : "”");
            flag = !flag;
        }
        else
            printf("%c", c);
    }
    return 0;
}