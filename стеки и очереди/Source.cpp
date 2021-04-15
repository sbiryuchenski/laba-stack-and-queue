#include <iostream>
#include <queue>

using namespace std;

static bool IsLand(int(*sea)[6], int i, int j, int len)
{
    if ((i < 0) || (i >= len)) return false;
    if ((j < 0) || (j >= len)) return false;

    bool island = sea[i][j] == 1;

    sea[i][j] = 0;

    if (island)
    {
        IsLand(sea, i, j + 1, len);
        IsLand(sea, i, j - 1, len);
        IsLand(sea, i + 1, j, len);
        IsLand(sea, i - 1, j, len);
    }

    return island;
}

void main()
{
    const int len = 6;

    int sea[len][len] =
    {
        {1, 1, 0, 0, 1, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 0},
    };

    int countlands = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (IsLand(sea, i, j, len))
            {
                countlands++;
            }
        }
    }

    cout << countlands;
}