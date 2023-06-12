#include <bits/stdc++.h>
using namespace std;

// 给定一个正整数 n ，将其拆分为 k 个正整数的和（k>=2）
// 使这些整数的乘积最大化。

// 动态规划
int integerBreak1(int n)
{
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; ++i)
    {
        for (int j = 2; j <= i / 2; ++j)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}

// 根据 n (n>=4)除以 3 的余数进行分类讨论：
// 如果余数为 0，即 n = 3m (m≥2)，则将 n 拆分成 m 个 3；
// 如果余数为 1，即 n = 3m+1(m≥1)，则将 n 拆分成 m−1 个 3 和 2 个 2；
// 如果余数为 2，即 n = 3m+2(m≥1)，则将 n 拆分成 m 个 3 和 1 个 2；

long long fastpow(long long a, int n)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int integerBreak2(int n)
{
    if (n <= 3)
        return n - 1;
    int m = n / 3, p = n % 3;
    if (p == 0)
        return fastpow(3, m);
    else if (p == 1)
        return 4 * fastpow(3, m - 1);
    else
        return 2 * fastpow(3, m);
}

int main()
{
    double start = clock();
    for (int i = 0; i < 100000; i++)
    {
        integerBreak1(100);
    }
    cout << "integerBreak1(100): " << clock() - start << endl;

    start = clock();
    for (int i = 0; i < 100000; i++)
    {
        integerBreak2(100);
    }
    cout << "integerBreak2(100): " << clock() - start << endl;
    return 0;
}
