/*
0 - 1
1 - 1
2 - 2
3 - 3
4 - 5
5 - 8
6 - 13
7 - 21
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int num_of_ways(int N)
{
    if (N == 0 || N == 1)
        return dp[N];

    for (int i = 2; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[N];
}
int main()
{
    const int N = 45;
    //initialization
    dp[0] = 1;
    dp[1] = 1;
    cout << "Total number of ways: " << num_of_ways(N) << endl;
    return 0;
}