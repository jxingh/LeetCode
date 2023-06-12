#include <bits/stdc++.h>
using namespace std;

// 1. 最基本的二分查找
int binarySearch(vector<int> A, int target)
{
    int left = 0, right = A.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] == target)
            return mid;
        else if (A[mid] > target)
            right = mid - 1;
        else if (A[mid] < target)
            left = mid + 1;
    }
    return -1;
}

// 2. 查找目标值区域的左边界
//    查找与目标值相等的第一个位置
int binarySearch(vector<int> A, int target)
{
    int left = 0, right = A.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] = target)
            right = mid - 1; // 收紧右边界
        else if (A[mid] > target)
            right = mid - 1;
        else if (A[mid] < target)
            left = mid + 1;
    }
    if (left < A.size() && A[left] == target)
        return left;
    else
        return -1;
}

// 3. 查找目标值区域的右边界
//    查找与目标值相等的最后一个位置
int binarySearch(vector<int> A, int target)
{
    int left = 0, right = A.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] = target)
            left = left + 1; // 收紧左边界
        else if (A[mid] < target)
            left = mid + 1;
        else if (A[mid] > target)
            right = mid - 1;
    }
    if (right >= 0 && A[right] == target)
        return right;
    else
        return -1;
}

// 4. 查找不小于目标值数的位置  (有相等的返回最后一个，没有相等的返回第一个比他大的)
int binarySearch(vector<int> A, int target)
{
    int left = 0, right = A.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] = target)
            right = mid - 1; // 收紧右边界
        else if (A[mid] > target)
            right = mid - 1;
        else if (A[mid] < target)
            left = mid + 1;
    }
    if (left < A.size())
        return left;
    else
        return -1;
}

// 5. 查找不大于目标值数的位置  (有相等的返回第一个，没有相等的返回最后一个比他小的)
int binarySearch(vector<int> A, int target)
{
    int left = 0, right = A.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (A[mid] = target)
            left = left + 1; // 收紧左边界
        else if (A[mid] < target)
            left = mid + 1;
        else if (A[mid] > target)
            right = mid - 1;
    }
    if (right >= 0)
        return right;
    else
        return -1;
}