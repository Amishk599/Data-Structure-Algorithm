#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
void initialize(int N, int sum)
{
    //initializing first row
    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;
    //initialzing first column
    for (int i = 0; i <= sum; i++)
        dp[i][0] = 1;
}
int num_ways(int coin[], int sum, int N)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                int choice1 = dp[i][j - coin[i - 1]];
                int choice2 = dp[i - 1][j];
                dp[i][j] = choice1 + choice2;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}
int main()
{
    int coin[] = {1, 2, 3};
    int N = sizeof(coin) / sizeof(coin[0]);
    int sum = 4;
    initialize(N, sum);
    cout << "Number of ways: " << num_ways(coin, sum, N);
    return 0;
}