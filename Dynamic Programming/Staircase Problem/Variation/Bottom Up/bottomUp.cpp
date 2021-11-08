#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int num_of_ways(int N)
{
    if (N == 0 || N == 1)
        return dp[N];

    for (int i = 2; i <= N; i++)
    {
        if (i < 3)
            dp[i] = dp[i - 1];
        else if (i < 5)
            dp[i] = dp[i - 1] + dp[i - 3];
        else
            dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 5];
    }
    return dp[N];
}
int main()
{
    const int N = 15;
    dp[0] = 1;
    dp[1] = 1;
    cout << "Total number of ways: " << num_of_ways(N) << endl;
    return 0;
}