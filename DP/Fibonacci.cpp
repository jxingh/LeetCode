#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n < 2)
        return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fib1(int n)
{
    if (n < 2)
        return n;
    int a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fib(n) << "\n"
         << fib1(n) << endl;
    return 0;
}
