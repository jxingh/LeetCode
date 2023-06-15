#include <bits/stdc++.h>
using namespace std;

// 将数组中小于 k 的整数组合到一起的最小交换次数。

int minSwapNum(vector<int> &nums, int k) {
    int cnt = 0;
    for (int &num : nums) {
        if (num < k)
            cnt++;
    }
    if (cnt == 0)
        return 0;
    int num = 0;
    for (int i = 0; i < cnt; i++) {
        if (nums[i] >= k)
            num++;
    }
    int res = num;
    for (int i = 0, j = cnt; j < nums.size(); i++, j++) {
        if (nums[i] >= k)
            num--;
        if (nums[j] >= k)
            num++;
        res = min(res, num);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minSwapNum(nums, k) << endl;
    return 0;
}