/* 尚且有误 */
#include <stdio.h>
#include <cstring>

#define BOUND 5
char grid[BOUND][BOUND];

int main()
{
    int x, y, error = 0;
    for (int i = 0; i < BOUND; i++) {
        scanf("%c", grid[i]);
        for (int j = 0; j < BOUND; j++) {
            if (grid[i][j] == ' ')
            {
                x = i;
                y = j;
            }
        }
    }
    char ins;
    while ((ins = getchar()) && ins != '0')
    {
        char tmp;
        switch (ins)
        {
        case 'A':
            if (x == 0)
                error = 1;
            else
            {
                tmp = grid[x][y];
                grid[x][y] = grid[x - 1][y];
                grid[x - 1][y] = tmp;
                x -= 1;
            }
            break;
        case 'B':
            if (x == BOUND - 1)
                error = 1;
            else
            {
                tmp = grid[x][y];
                grid[x][y] = grid[x + 1][y];
                grid[x + 1][y] = tmp;
                x += 1;
            }
            break;
        case 'L':
            if (y == 0)
                error = 1;
            else
            {
                tmp = grid[x][y];
                grid[x][y] = grid[x][y - 1];
                grid[x][y - 1] = tmp;
                y -= 1;
            }
            break;
        case 'R':
            if (y == BOUND - 1)
                error = 1;
            else
            {
                tmp = grid[x][y];
                grid[x][y] = grid[x][y + 1];
                grid[x][y + 1] = tmp;
                y += 1;
            }
            break;
        }
    }
    if (!error)
    {
        for (int i = 0; i < BOUND; i++)
        {
            for (int j = 0; j < BOUND; j++)
                putchar(grid[i][j]);
            printf("\n");
        }
    }
    else
        printf("This puzzle has no final configuration.");
    return 0;
}