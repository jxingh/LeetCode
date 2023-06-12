/* sort.cpp */
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

// 1.直接插入排序
void insertSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            int tmp = nums[i];
            int j = i - 1;
            for (; j >= 0 && nums[j] > tmp; j--) {
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = tmp;
        }
    }
}

// 2.希尔排序
void shellSort(vector<int> &nums) {
    int len = nums.size();
    for (int dk = len / 2; dk >= 1; dk /= 2) {
        for (int i = dk; i < len; i++) {
            if (nums[i] < nums[i - dk]) {
                int tmp = nums[i];
                int j;
                for (j = i - dk; j >= 0 && nums[j] >= tmp; j -= dk) {
                    nums[j + dk] = nums[j];
                }
                nums[j + dk] = tmp;
            }
        }
    }
}

// 3.冒泡排序
void bubbleSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        bool flag = false;
        for (int j = nums.size() - 1; j > i; j--) {
            if (nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

// 4.快速排序
void quick_sort(vector<int> &nums, int l, int r) {
    if (l < r) {
        int i = l, j = r, pivot = nums[l];
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
        nums[i] = pivot;
        quick_sort(nums, l, i - 1);
        quick_sort(nums, i + 1, r);
    }
}

void quickSort(vector<int> &nums) {
    quick_sort(nums, 0, nums.size() - 1);
}

// 5.简单选择排序
void selectSort(vector<int> &nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min])
                min = j;
        }
        if (min != i) {
            swap(nums[i], nums[min]);
        }
    }
}

// 6.堆排序
void heapAdjust(vector<int> &nums, int start, int end) {
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end) {
        if (son + 1 <= end && nums[son] < nums[son + 1]) {
            son++;
        }
        if (nums[dad] > nums[son])
            return;
        else {
            swap(nums[dad], nums[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void heapSort(vector<int> &nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapAdjust(nums, i, len - 1);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapAdjust(nums, 0, i - 1);
    }
}

// 7.二路归并排序
void merge(vector<int> &nums, vector<int> &help, int left, int right) {
    if (left < right) {
        int mid = left + ((right - left) >> 1);
        merge(nums, help, left, mid);
        merge(nums, help, mid + 1, right);
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            help[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) {
            help[k++] = nums[i++];
        }
        while (j <= right) {
            help[k++] = nums[j++];
        }
        for (k = left; k <= right; k++) {
            nums[k] = help[k];
        }
    }
}

void mergeSort(vector<int> &nums) {
    vector<int> help(nums.size(), 0);
    merge(nums, help, 0, nums.size() - 1);
}

// 8.计数排序
void countSort(vector<int> &nums, int maxVal) {
    int len = nums.size();
    if (len < 1)
        return;
    vector<int> count(maxVal + 1, 0);
    vector<int> tmp(nums);
    for (auto x : nums)
        count[x]++;
    for (int i = 1; i <= maxVal; ++i)
        count[i] += count[i - 1];
    // 从后往前遍历保证稳定性
    for (int i = len - 1; i >= 0; --i) {
        count[tmp[i]]--;
        nums[count[tmp[i]]] = tmp[i];
    }
}

void print(vector<int> &nums) {
    for (auto it : nums) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {7, 1, 3, 2, 9, 6, 11, 10, 15, 8, 9, 7};

    double start = clock();

    for (int i = 0; i < 1000; i++) {
        vector<int> nums1 = nums;
        insertSort(nums1);
    }
    // print(nums1);
    cout << "insert: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums2 = nums;
        shellSort(nums2);
    }
    // print(nums2);
    cout << "shell: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums3 = nums;
        bubbleSort(nums3);
    }
    // print(nums3);
    cout << "bubble: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums4 = nums;
        quickSort(nums4);
    }
    // print(nums4);
    cout << "quick: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums5 = nums;
        selectSort(nums5);
    }
    // print(nums5);
    cout << "select: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums6 = nums;
        heapSort(nums6);
    }
    // print(nums6);
    cout << "heap: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums7 = nums;
        mergeSort(nums7);
    }
    // print(nums7);
    cout << "merge: " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 1000; i++) {
        vector<int> nums8 = nums;
        countSort(nums8, 20);
    }
    // print(nums8);
    cout << "count: " << clock() - start << endl;

    return 0;
}
