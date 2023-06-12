#include <bits/stdc++.h>
using namespace std;

int quick_select(vector<int> &nums, int start, int end, int k) {
    int pivot = nums[start];
    int i = start, j = end;
    while (i < j) {
        while (i < j && nums[j] >= pivot)
            j--;
        if (i < j)
            nums[i++] = nums[j];
        while (i < j && nums[i] <= pivot)
            i++;
        if (i < j)
            nums[j--] = nums[i];
    }
    if (i == k - 1) {
        return pivot;
    } else if (i < k - 1) {
        return quick_select(nums, i + 1, end, k);
    } else {
        return quick_select(nums, start, i - 1, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << quick_select(nums, 0, n - 1, k) << endl;
    return 0;
}
