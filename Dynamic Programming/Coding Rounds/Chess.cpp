#include <bits/stdc++.h>
using namespace std;
int Ri, Rj;
int Bi, Bj;
int Qi, Qj;
int row, col;
void findCurrentPosition(vector<vector<char>> a)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //current position of R
            if (a[i][j] == 'R')
            {
                Ri = i;
                Rj = j;
            }
            //current position of P
            if (a[i][j] == 'B')
            {
                Bi = i;
                Bj = j;
            }
            //current position of Q
            if (a[i][j] == 'Q')
            {
                Qi = i;
                Qj = j;
            }
        }
    }
}
int movesOfR(int i, int j, vector<vector<char>> a)
{
    if (j == col || j < 0 || i == row || i < 0 || a[i][j] == 'B' || a[i][j] == 'Q')
        return 0;

    int right = 0;
    right += movesOfR(i, j + 1, a);
    int left = 0;
    left += movesOfR(i, j - 1, a);
    int up = 0;
    up += movesOfR(i + 1, j, a);
    int down = 0;
    down += movesOfR(i - 1, j, a);
    return up + down + left + right;
}

int movesOfB(int i, int j, vector<vector<char>> a)
{
    if (j == col || j < 0 || i == row || i < 0 || a[i][j] == 'R' || a[i][j] == 'Q')
        return 0;
    if (a[i][j] == '.')
        return 1;
    int upRight = 0;
    upRight += movesOfB(i + 1, j + 1, a);
    int downRight = 0;
    downRight += movesOfB(i - 1, j + 1, a);
    int upLeft = 0;
    upLeft += movesOfB(i + 1, j - 1, a);
    int downLeft = 0;
    downLeft += movesOfB(i - 1, j - 1, a);
    return upRight + downRight + upLeft + downLeft;
}

int movesOfQ(int i, int j, vector<vector<char>> a)
{
    if (j == col || j < 0 || i == row || i < 0 || a[i][j] == 'R' || a[i][j] == 'B')
        return 0;
    if (a[i][j] == '.')
        return 1;
    //moves of R
    int right = 0;
    right += movesOfR(i, j + 1, a);
    int left = 0;
    left += movesOfR(i, j - 1, a);
    int up = 0;
    up += movesOfR(i + 1, j, a);
    int down = 0;
    down += movesOfR(i - 1, j, a);
    //moves of B
    int upRight = 0;
    upRight += movesOfB(i + 1, j + 1, a);
    int downRight = 0;
    downRight += movesOfB(i - 1, j + 1, a);
    int upLeft = 0;
    upLeft += movesOfB(i + 1, j - 1, a);
    int downLeft = 0;
    downLeft += movesOfB(i - 1, j - 1, a);
    return up + down + left + right + upRight + downRight + upLeft + downLeft;
}
int solve(vector<vector<char>> a)
{
    row = a.size();
    col = a[0].size();
    findCurrentPosition(a);
    return movesOfR(Ri, Rj, a) + movesOfB(Bi, Bj, a) + movesOfQ(Qi, Qj, a);
}
int main()
{
    vector<vector<char>> chessboard{{'.', 'R', '.'}, {'.', '.', '.'}, {'B', 'Q', '.'}};
    cout << solve(chessboard);
    return 0;
}