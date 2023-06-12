#include <bits/stdc++.h>
using namespace std;

int L, N, M, a[50005];

bool check(int k) {
    int ans = 0 , pos = 0;
    for(int i = 1; i <= N + 1; i++) {
        if(a[i] - a[pos] < k) {
            ans++;
        }
        else {
            pos = i;
        }
    }
    return ans <= M;
}

int main() {
    cin >> L >> N >> M;
    a[0] = 0, a[N + 1] = L;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int l = 0, r = L, mid;
    int ans;
    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}