#include <bits/stdc++.h>
using namespace std;
int seatPlan[20][20];
void printSeatPlan(int N)
{
    cout << "\n---seatplan---" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 3)
                cout << " ";
            if (j == 7)
                cout << " ";
            cout << seatPlan[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void occupiedSeats(string rez, int N)
{
    unordered_map<char, int> m;
    char ch = 'A';
    for (int i = 0; i < 10; i++)
    {
        if (i == 8)
            ch++;
        m.insert(make_pair(ch, i));
        ch++;
    }
    //matrix initialization
    string str = "";
    for (int i = 0; i <= rez.length(); i++)
    {
        char ch = rez[i];
        if (ch != ' ')
            str += ch;

        if (ch == ' ' || i == rez.size() - 1)
        {
            int col = m[str[str.size() - 1]];
            string row_str = str.substr(0, str.size() - 1);
            int row = stoi(row_str);
            seatPlan[row - 1][col] = 1;
            str.clear();
        }
    }
}
int allocation(int N)
{
    int count = 0;
    for (int row = 0; row < N; row++)
    {
        //checking if 2 famlies can be accomodates
        int flag = 2, col = 1;
        while (col < 10)
        {
            if (col < 5 && seatPlan[row][col] == 1)
            {
                col = 5;
                flag--;
            }
            if (col >= 5 && col < 9 && seatPlan[row][col] == 1)
            {
                flag--;
                col = 10;
            }
            col++;
        }
        if (flag == 0)
        {
            flag = 1;
            col = 3;
            while (col < 7)
            {
                if (seatPlan[row][col] == 1)
                {
                    flag--;
                    break;
                }
                col++;
            } //while
        }
        count += flag;
    }
    return count;
}
int main()
{
    string rez = "1A 2F 1C 3D 1J 4K 5F 2C 10A 10G 12D";
    int N = 12;
    memset(seatPlan, 0, sizeof(seatPlan));
    occupiedSeats(rez, N);
    int ans = allocation(N);
    printSeatPlan(N);
    cout << "Ans: " << ans << endl;

    return 0;
}
