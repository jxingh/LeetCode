#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // 注意3：数组长度不够
    if (nums.size() < 4)
        return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int left = 0, right = 0;
    for (int i = 0; i < nums.size() - 3; i++)
    {
        // 注意1：不要少 nums[i] >= 0
        if (nums[i] > target && nums[i] >= 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            left = j + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                // 注意2：int型范围
                if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    right--;
                else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    left++;
                else
                {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
}