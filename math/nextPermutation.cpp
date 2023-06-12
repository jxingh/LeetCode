#include <bits/stdc++.h>
using namespace std;

/*
1. 首先从后向前查找第一个顺序对 (i, i+1), 满足 a[i] < a[i+1]，此时 [i+1, n) 降序
2. 如果找到了顺序对，在区间 [i+1, n) 从后往前找到第一个元素 j 满足 a[j] > a[i]
3. 交换 a[i] 与 a[j]，此时 [i+1, n) 还是降序，反转区间 [i+1, n) 即可
*/

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    for (; i >= 0; --i) {
        if (nums[i] < nums[i + 1])
            break;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        for (; j > i; --j) {
            if (nums[j] > nums[i])
                break;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> nums1 = nums;

    nextPermutation(nums);

    // STL 全排列函数
    next_permutation(nums1.begin(), nums1.end());

    for (int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
    for (int& num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}