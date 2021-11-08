//FILLING FIRST COL AND ROW WITH 0s
/*
profit[]    wt[]           | [0]  [1]  [2]  [3]   [4]   [5]   [6]   [7]
-------------------------  |  0    0    0    0     0     0     0     0   [0]
    1         1     item 1 |  0    1    1    1     1     1     1     1   [1]
    6         2     item 2 |  0    1    6    7     7     7     7     7   [2]
    10        3     item 3 |  0    1    6    10    11    16    17    17  [3]
    16        5     item 4 |  0    1    6    10    11    16    17    22  [4]
*/

#include <bits/stdc++.h>
using namespace std;
int dp[20][21];
int bottomUp(int wt[], int profit[], int N, int C)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            int profit1 = 0, profit2 = 0;
            if (wt[i - 1] <= j)
            {
                profit1 = profit[i - 1] + dp[i - 1][j - wt[i - 1]];
                profit2 = dp[i - 1][j];
                dp[i][j] = max(profit1, profit2);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][C];
}
void printMatrix(int a, int b)
{
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
            cout << dp[i][j] << "    ";
        cout << endl;
    }
}
int main()
{
    int wt[] = {1, 2, 3, 5};
    int profit[] = {1, 6, 10, 16};
    int C = 7;
    int N = sizeof(profit) / sizeof(profit[0]);

    //filling the first row with 0s
    for (int i = 0; i <= N; i++)
        dp[i][0] = 0;

    //filling the first column with 0s
    for (int i = 0; i <= C; i++)
        dp[0][i] = 0;

    int ans = bottomUp(wt, profit, N, C);
    cout << "Max profit using bottom up approach: " << ans << endl;
    printMatrix(N, C);
    return 0;
}