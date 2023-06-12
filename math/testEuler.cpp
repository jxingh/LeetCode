#include <bits/stdc++.h>
using namespace std;

// 小于n里与n互质的数的个数
int euler(int n)
{
    int ans = n;
    for (int i = 2; i * i <= ans; i++)
    {
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        ans = ans / n * (n - 1);
    }
    return ans;
}

// a*b == k 多少对互质的(a,b)
int fun1(int k)
{
}