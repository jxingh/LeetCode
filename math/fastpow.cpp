#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9;

// a 的 n 次方
int fastpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = (a * res) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int a;
    int n;
    cin >> a >> n;
    cout << fastpow(a, n) << endl;
    return 0;
}