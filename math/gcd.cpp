#include <bits/stdc++.h>
using namespace std;

// 最大公因数：gcd(a, b)
// 最小公倍数：lcm(a, b) = a*b/gad(a,b)
// 辗转相除法：gcd(a, b) = gcd(b, a%b)
// 更相减损术：gcd(a, b) = gcd(b, a-b)

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int gcd1(int a, int b)
{
    int rem = 0;
    while (b)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main()
{
    int start = clock();
    int a = 0;
    for (int i = 0; i < 100000000; i++)
    {
        a = gcd(10254894, 15649776);
    }
    cout << "1: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s " << a << endl;

    start = clock();
    int b = 0;
    for (int i = 0; i < 100000000; i++)
    {
        b = gcd1(10254894, 15649776);
    }
    cout << "2: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s " << b << endl;
    return 0;
}
