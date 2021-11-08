/*People in Cubeland use cubic coins. Not only the unit of currency is called a cube but also the coins are shaped like cubes and their values are cubes. Coins with values of all cubic numbers up to 9261(=21³), i.e.. coins with the denominations of 1, 8, 27....., up to 9261 cubes, are available in Cubeland.

Your task is to count the number of ways to pay a given amount using cubic coins of Cubeland. For example, there are 3 ways to pay 21 cubes: twenty-one 1 cube coins, or one 8 cube coin and thirteen 1 cube coins, or two 8 cube coin and five 1 cube coins.

Input Format:
Input containing a single an integer amount to be paid. You may assume that all the amounts are positive and less than 10000.

Output Format:

Output containing a single integer representing the number of ways to pay the given amount using the coins available in Cubeland.

Note: Refer Sample Input and Sample Output for formatting specifications.

Sample Input 1:

10

Sample Output 1:

2

Explanation:
There are 2 ways to pay 10 cubes: ten 1 cube coins [ 10*1 = 10], or one 1 cube coin and one 9 cube coin [(1*1) + (1*9) = 10].

Sample Input 2:

21

Sample Output 2:

3

*/

#include <bits/stdc++.h>
using namespace std;
int waysToPay(int i, int amount)
{

    if (i > 21)
        return 0;

    if (amount == 0)
        return 1;

    if (amount < 0)
        return 0;

    return waysToPay(i, amount - pow(i, 3)) + waysToPay(i + 1, amount - pow(i + 1, 3));
}

int main()
{
    int amount = 134;
    int startingCurrency = 1;
    int ans = waysToPay(startingCurrency, amount);
    cout << "Number of ways to pay: " << ans;
    return 0;
}