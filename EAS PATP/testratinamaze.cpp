#include <stdio.h>

int solution[10][10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int maze[10][10] = {
    1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    1, 0, 1, 1, 0, 0, 1, 1, 0, 0,
    1, 1, 1, 1, 0, 1, 0, 0, 1, 0,
    0, 0, 1, 1, 0, 0, 0, 1, 1, 0,
    1, 0, 1, 1, 0, 1, 1, 0, 1, 0,
    1, 0, 1, 1, 0, 0, 1, 0, 1, 0,
    1, 0, 1, 1, 1, 0, 0, 1, 1, 1,
    1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
    1, 1, 1, 0, 0, 0, 0, 1, 1, 1,
    0, 0, 1, 1, 1, 1, 1, 1, 0, 1};

int carijalan(int i, int j, int n)
{
    if (i == n - 1 && j == n - 1) {// destination
        solution[i][j] = 1;
        return 1;
    }

    if (maze[i][j] == 1)
    {
        solution[i][j] = 1;

        if (carijalan(i + 1, j, n) == 1) { // treading downwards with i as row index
            return 1;
        }

        if (carijalan(i, j + 1, n) == 1) { // treading to the right with j as column index
            return 1;
        }

        solution[i][j] = 0;
    }
    return 0;
}

int main()
{
    carijalan(0, 0, 10); // dimulai dari baris kolom (0,0)

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (solution[i][j])
                printf("(%d,%d) --> ", i+1, j+1);
        }
    }

    printf("\nFinish");
    return 0;
}