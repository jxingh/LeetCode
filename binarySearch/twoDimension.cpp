#include <bits/stdc++.h>
using namespace std;

// 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素

// 计算 matrix 里小于等于 mid 的元素个数
int count(vector<vector<int>> &matrix, int mid) {
    int n = matrix.size();
    int i = 0;
    int j = n - 1;
    int num = 0;
    while (i < n && j >= 0) {
        if (matrix[i][j] <= mid) {
            num += j + 1;
            i++;
        } else {
            j--;
        }
    }
    return num;
}

int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    int ans = left;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (count(matrix, mid) >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}