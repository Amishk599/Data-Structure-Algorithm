#include <bits/stdc++.h>
using namespace std;
int dp[102][1002]; //for the problem 102 and 1002 are the constraints
int knapsack(const int wt[], const int profit[], int i, int C)
{
    if (i < 0 || C < 0)
        return 0;

    if (dp[i][C] != -1)
        return dp[i][C];

    if (wt[i] > C)
    {
        dp[i][C] = knapsack(wt, profit, i - 1, C);
        return dp[i][C];
    }

    int inlcude = profit[i] + knapsack(wt, profit, i - 1, C - wt[i]); // including the current item
    int exclude = knapsack(wt, profit, i - 1, C);                     //not including the current item
    dp[i][C] = max(inlcude, exclude);
    return dp[i][C];
}

void printMatrix(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << dp[i][j] << "    ";
        cout << endl;
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int wt[] = {1, 3, 4, 5};
    int profit[] = {1, 4, 5, 7};
    int C = 7;
    int N = sizeof(wt) / sizeof(wt[0]);
    cout << "Maximum profit: " << knapsack(wt, profit, N - 1, C) << endl;
    printMatrix(N + 2, C + 2);
    return 0;
}
