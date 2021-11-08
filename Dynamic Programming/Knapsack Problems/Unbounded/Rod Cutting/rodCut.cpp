#include <bits/stdc++.h>
using namespace std;
int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
int N = sizeof(length) / sizeof(length[0]);
int dp[100][100];
void printMatrix(int a, int b)
{
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
            cout << dp[i][j] << "    ";
        cout << endl;
    }
}
void initialization()
{
    //initializing first row and column with 0s
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
}
int computeProfit()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (length[i - 1] <= j)
            {
                int profit1 = price[i - 1] + dp[i][j - length[i - 1]];
                int profit2 = dp[i - 1][j];
                dp[i][j] = max(profit1, profit2);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][N];
}
int main()
{
    int profit;
    initialization();
    profit = computeProfit();
    cout << "Maximum profit: " << profit << endl;
    printMatrix(N, N);
    return 0;
}