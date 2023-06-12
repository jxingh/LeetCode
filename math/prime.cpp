#include <bits/stdc++.h>
// #include <time.h>
using namespace std;

// 素数(质数)：一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数。
//   结论：如果一个数不能整除比它小的任何素数，那么这个数就是素数;
//         大于等于5的质数一定和6的倍数相邻

// 判断 n 是不是素数的最快方法
// bool isPrime(int n)
// {
//     if (n == 1)
//         return false;
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 6 != 1 && n % 6 != 5)
//         return false;
//     // 只用判断 6x-1 和 6x+1
//     for (int i = 5; i * i <= n; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }

// 埃氏筛：判断 2 ~ n 里面的素数
const int MAX = 1000010;
// bool isnp[MAX]; // is not prime

// void init(int n)
// {
//     isnp[0] = isnp[1] = 1;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (!isnp[i]) // 是素数
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 cout << j << " ";
//                 isnp[j] = 1;
//             }
//             cout << endl;
//         }
//     }
// }

// 欧拉筛：判断 2 ~ n 里面的素数
// vector<bool> isPrime(MAX, true);
// vector<int> prime(MAX, 0);

vector<int> init(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> prime;
    isPrime[0] = false;
    isPrime[1] = false;
    int size = 0; // 纪录素数个数
    for (int i = 2; i <= n; i++)
    {
        // cout << "i = " << i << endl;
        if (isPrime[i]) // 是素数
        {
            prime.push_back(i);
            size++;
        }
        for (int j = 0; j < size && i * prime[j] <= n; j++)
        {
            // cout << "  j = " << j << " prime[" << j << "]"
            //      << " = " << prime[j] << " i*prime[j] = " << i * prime[j] << endl;
            isPrime[i * prime[j]] = false; // 不是素数
            if (i % prime[j] == 0)
                break;
        }
    }
    return prime;
}

// void init1(int n)
// {
//     isPrime[0] = false;
//     isPrime[1] = false;
//     // memset(prime, 0, sizeof(prime));
//     for (int i = 2; i <= n; i++)
//     {
//         cout << "i = " << i << endl;
//         if (isPrime[i]) // 是素数
//         {
//             prime[++prime[0]] = i; // prime[0] 纪录素数个数
//         }
//         for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++)
//         {
//             // cout << "  j = " << j << " prime[" << j << "]"
//             //      << " = " << prime[j] << " i*prime[j] = " << i * prime[j] << endl;
//             isPrime[i * prime[j]] = false; // 不是素数
//             if (i % prime[j] == 0)
//                 break;
//         }
//     }
// }

int main()
{
    int n;
    cin >> n;
    // int start = clock();
    // for (int i = 0; i < 1000000; i++)
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         if (isPrime(i))
    //             ;
    //     }
    // }
    // cout << "1: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;

    // start = clock();
    // for (int i = 0; i < 1000000; i++)
    // {
    //     init(n);
    //     for (int i = 2; i <= n; i++)
    //     {
    //         if (!isnp[i])
    //             ;
    //     }
    // }
    // cout << "2: " << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
    // int num = 0;
    // for (int i = 2; i <= n; i++)
    // {
    //     if (isPrime(i))
    //         num++;
    // }
    // cout << num << endl;

    vector<int> res = init(n);
    for (auto it : res)
    {
        cout << it << endl;
    }
    return 0;
}