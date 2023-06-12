#include <bits/stdc++.h>
using namespace std;

void printUglyNumber(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        int num1 = dp[p2] * 2, num2 = dp[p3] * 3, num3 = dp[p5] * 5;
        dp[i] = min(num1, min(num2, num3));
        if (dp[i] == num1)
            p2++;
        if (dp[i] == num2)
            p3++;
        if (dp[i] == num3)
            p5++;
    }
    for (int i = 1; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << dp[n] << endl;
}

int main() {
    int n;
    cin >> n;
    printUglyNumber(n);
    return 0;
}