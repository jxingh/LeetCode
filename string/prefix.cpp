#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e5 + 1;
 
int Next[MAXN], ans[MAXN];


void getNext(string s) {
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < s.size()) {
		if (j == -1 || s[i] == s[j]) {
			i++;
			j++;
			Next[i] = j;
		} else {
			j = Next[j];
		}
	}
	Next[0] = 0;
}
 
int main() {

    string str;
	cin >> str;
	int len = str.length();
	getNext(str);	// KMP
	long long cnt = 0;
	memset(ans, 0, len + 1);
	for (int i = 1; i <= len; i++) {
		ans[i] = ans[Next[i]];
		ans[i]++;
		cnt += ans[i];
	}
	cout << cnt << endl;

	return 0;
}

//   eg: a b c a b c a b
// next: 0 0 0 0 1 2 3 4 5
//  ans: 0 1 1 1 2 2 2 3 3     ans[i] 表示以 s[i-1] 为结尾的字串里能够构成前缀的个数
