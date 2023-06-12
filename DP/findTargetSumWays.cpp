#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (auto it : nums)
        sum += it;
    if (sum < abs(target))
        return 0;
    if ((sum - target) & 1)
        return 0;
    int bagWeight = (sum - target) / 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(bagWeight + 1, 0));
    // dp[i][j] 表示在数组 nums 的前 i(i从1开始) 个数中选取元素，使得这些元素之和等于 j 的方案数
    dp[0][0] = 1; // 啥也不选的情况下元素和为 0 的方案数为 1
    for (int i = 1; i <= nums.size(); ++i)
    {
        for (int j = 0; j <= nums[i]; ++j)
        {
            if (j < nums[i - 1])
            {
                dp[i][j] = dp[i - 1][j]; // 不能选 nums[i - 1]
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]; // 选 nums[i - 1] or 不选
            }
        }
    }
    return dp[nums.size()][bagWeight];
}