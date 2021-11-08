#include <bits/stdc++.h>
using namespace std;

int dp[500000];
int solution(int N, int K)
{
    if (N == 0 || N == 1)
        return 1;

    if (dp[N] != 0)
        return dp[N];

    if (K >= 1)
        dp[N] = solution(N - 3, K - 1) + solution(N - 1, K - 1) + solution(N - 2, K - 1);
    else
        dp[N] = solution(N - 2, 0) + solution(N - 1, 0);

    return dp[N] % (1000000000 + 7);
}

int main()
{
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int K;
        cin >> K;
        int out_ = solution(N, K);
        cout << out_;
        cout << "\n";
    }
}