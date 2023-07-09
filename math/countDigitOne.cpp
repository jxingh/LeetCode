#include <bits/stdc++.h>
using namespace std;

// 数字 1 的个数：给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

int countDigitOne(int n) {
    int res = 0, num = n;
    long long dight = 1;
    while (num) {
        int cur = num % 10, high = num / 10, low = n % dight;
        if (cur == 0) {
            res += high * dight;
        } else if (cur == 1) {
            res += high * dight + low + 1;
        } else {
            res += (high + 1) * dight;
        }
        num /= 10;
        dight *= 10;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << countDigitOne(n) << endl;
    return 0;
}
