
/*
                                            CHOICE DIAGRAM OF 0-1 KNAPSACKPROBLEM
                                            -------------------------------------
                                                            ITEM 1
                                                             (w1)
                                                            /    \
                                                           /      \
                                                       w1<C        w1>C
                                                       /  \          |
                                                      /    \         |
                                                   Take   Leave     Leave

IDEAL SOLUTION CODE
-------------------
int knapsack(int wt[], int val[], int C, int N)
{
    if (N == 0 || C == 0)
        return 0;

    if (wt[N] > C)
        return knapsack(wt[], val[], C, N - 1);

    return max(val[N] + knapsack(wt[], val[], C - wt[N], N - 1), knapsack(wt[], val[], C, N - 1));
}


ANOTHER WAY OF WRITING THE ABOVE THING
--------------------------------------
int knapsack(int wt[], int val[], int C, int N)
{
    if (N == 0 || C == 0)
        return 0;

    if (wt[N] > C){
        int exclude = knapsack(wt[], val[], C, N - 1);
        return exclude;
    }
        
    int include = val[N] + knapsack(wt[], val[], C - wt[N], N - 1);
    int exclude = knapsack(wt[], val[], C, N - 1);
    
    return max(include, exclude);
}

*/

#include <bits/stdc++.h>
using namespace std;
int static T[102][1002];
int knapsack(int wt[], int val[], int C, int N)
{
    if (N < 0 || C <= 0)
        return 0;

    if (T[N][C] != -1)
        return T[N][C];

    if (wt[N] > C)
    {
        T[N][C] = knapsack(wt, val, C, N - 1);
        return T[N][C];
    }

    T[N][C] = max(val[N] + knapsack(wt, val, C - wt[N], N - 1), knapsack(wt, val, C, N - 1));
    return T[N][C];
}
int main()
{
    memset(T, -1, sizeof(T));
    int wt[] = {4, 5, 1, 3, 2, 5};
    int val[] = {2, 3, 1, 5, 4, 7};
    int size = sizeof(wt) / sizeof(wt[0]);
    int C = 30;
    int ans = knapsack(wt, val, C, 3);
    cout << ans;
    return 0;
}