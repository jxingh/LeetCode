#include <bits/stdc++.h>
using namespace std;

void test_01bag(vector<int> &weights, vector<int> &values, int bagweight)
{
    vector<vector<int>> dp(weights.size(), vector<int>(bagweight + 1, 0));
    for (int j = weights[0]; j <= bagweight; ++j)
    {

        dp[0][j] = values[0];
    }
    for (int i = 1; i < weights.size(); ++i)
    {
        for (int j = 1; j <= bagweight; ++j)
        {
            if (j < weights[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    for (int i = 0; i < weights.size(); ++i)
    {
        for (int j = 0; j <= bagweight; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void test1_01bag(vector<int> &weights, vector<int> &values, int bagweight)
{
    vector<int> dp(bagweight + 1, 0);

    for (int i = 0; i < weights.size(); ++i)
    {
        for (int j = bagweight; j >= weights[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            cout << "dp[" << j << "]= " << dp[j] << " ";
        }
        cout << endl;
    }
    // for (int j = 0; j <= bagweight; j++)
    // {
    //     cout << dp[j] << " ";
    // }
}

int main()
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 8};
    int bagweight = 8;
    test_01bag(weights, values, bagweight);
    test1_01bag(weights, values, bagweight);
    return 0;
}