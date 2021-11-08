#include <bits/stdc++.h>
using namespace std;
pair<long, long> num_of_zeros_sol(int N, unordered_map<int, pair<long, long>> &mapp)
{
    if (N == 1)
    {
        pair<long, long> val;
        val.first = 3;
        val.second = 2;
        return val;
    }

    if (N == 2)
    {
        pair<long, long> val;
        val.first = 4;
        val.second = 3;
        return val;
    }

    if (mapp.count(N) == 1)
        return mapp[N];

    pair<long, long> ans, X, Y;
    X = num_of_zeros_sol(N - 1, mapp);
    Y = num_of_zeros_sol(N - 2, mapp);
    ans.first = X.first + (3 * Y.second);
    ans.second = (2 * X.second) + (2 * Y.first);
    mapp[N] = ans;
    return ans;
}
int main()
{
    int T, N;
    pair<long, long> ans;
    vector<long> result;
    unordered_map<int, pair<long, long>> mapp;
    cin >> T;
    while (T-- > 0)
    {
        cin >> N;
        ans = num_of_zeros_sol(N, mapp);
        result.push_back(ans.first);
    }
    cout << "" << endl;
    for (long ele : result)
        cout << ele << endl;
    return 0;
}
