#include <bits/stdc++.h>
using namespace std;

// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
// 单调队列 + 滑动窗口

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int len = nums.size();
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vector<int> res;
    res.push_back(nums[dq.front()]);
    for (int i = k; i < len; i++) {
        if (i - dq.front() == k) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        res.push_back(nums[dq.front()]);
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
    vector<int> res = maxSlidingWindow(nums, k);
    for (auto &num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}