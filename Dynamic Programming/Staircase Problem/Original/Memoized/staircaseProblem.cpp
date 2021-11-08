#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int num_of_ways(int N)
{
    if (N == 0 || N == 1)
        return 1;

    if (dp[N] != 0)
        return dp[N];

    dp[N] = num_of_ways(N - 1) + num_of_ways(N - 2);

    return dp[N];
}
int main()
{
    const int N = 4;
    cout << "Total number of ways: " << num_of_ways(N) << endl;
    return 0;
}