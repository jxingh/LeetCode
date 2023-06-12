#include <bits/stdc++.h>
using namespace std;

int climb(vector<int> &cost)
{
    int len = cost.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    dp[1] = 0;
    cout << dp[1] << " ";
    for (int i = 2; i <= len; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[len];
}

int climb(vector<int> &cost)
{
    int len = cost.size();
    vector<int> dp(len + 1);
    dp[0] = 0;
    dp[1] = 0;
    cout << dp[1] << " ";
    for (int i = 2; i <= len; i++)
    {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[len];
}

int main()
{
    vector<int> nums = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << climb(nums) << endl;
    return 0;
}
