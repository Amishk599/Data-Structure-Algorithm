#include <bits/stdc++.h>
using namespace std;
int ans[] = {-1, -1};
void runner(int i, int j, char glass, int count, int N, int M, int index, vector<vector<char>> maze)
{

    if (i == N - 1 && j == M - 1)
    {
        ans[index] = count;
        return;
    }
    if (i == N || j == M)
        return;

    if (maze[i][j] != glass && maze[i][j] != '.')
        return;

    runner(i, j + 1, glass, count + 1, N, M, index, maze);
    runner(i + 1, j, glass, count + 1, N, M, index, maze);
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> maze;
    for (int i = 1; i <= N; i++)
    {
        vector<char> v;
        for (int j = 1; j <= M; j++)
        {
            char x;
            cin >> x;
            v.push_back(x);
        }
        maze.push_back(v);
    }
    runner(0, 0, '#', 0, N, M, 0, maze);
    runner(0, 0, '*', 0, N, M, 1, maze);
    cout << ans[0] << endl
         << ans[1];
    return 0;
}