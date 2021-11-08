#include <bits/stdc++.h>
using namespace std;
int ways = 0;
unordered_map<int, int> dp;
int num_of_ways(int N)
{
    if (N == 0 || N == 1)
        return 1;

    if (N < 0)
        return 0;

    if (dp.count(N))
        return dp[N];

    dp[N] = num_of_ways(N - 1) + num_of_ways(N - 3) + num_of_ways(N - 5);
    return dp[N];
}
int main()
{
    const int N = 15;
    cout << "Total number of ways: " << num_of_ways(N) << endl;
    for (auto itr = dp.begin(); itr != dp.end(); itr++)
        cout << itr->first << " : " << itr->second << endl;

    return 0;
}