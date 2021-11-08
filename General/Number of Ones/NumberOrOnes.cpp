#include <bits/stdc++.h>
using namespace std;
pair<long, long> num_of_zeros_sol(int N)
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

    pair<long, long> ans;
    ans.first = num_of_zeros_sol(N - 1).first + (3 * num_of_zeros_sol(N - 2).second);
    ans.second = (2 * num_of_zeros_sol(N - 1).second) + (2 * num_of_zeros_sol(N - 2).first);
    return ans;
}
int main()
{
    int T, N;
    pair<long, long> ans;
    vector<long> result;
    cin >> T;
    while (T-- > 0)
    {
        cin >> N;
        ans = num_of_zeros_sol(N);
        result.push_back(ans.first);
    }

    for (long ele : result)
        cout << ele << endl;
    return 0;
}
