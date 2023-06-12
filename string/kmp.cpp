#include <bits/stdc++.h>
using namespace std;

void getNext(const string &p, vector<int> &next) {
    int plen = p.length();
    for (int i = 1, j = 0; i < plen; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

void KMP(string t, string p) {
    int tlen = t.length();
    int plen = p.length();
    vector<int> next(plen, 0);
    getNext(p, next);
    for (int i = 0, j = 0; i < tlen; i++) {
        while (j > 0 && t[i] != p[j]) {
            j = next[j - 1];
        }
        if (t[i] == p[j]) {
            j++;
        }
        if (j == plen) {
            cout << i - plen + 1 << endl;
            j = next[j - 1];
        }
    }
}

int main() {
    string t = "aaaaaaaaaaaaa";
    string p = "aa";
    KMP(t, p);
    return 0;
}