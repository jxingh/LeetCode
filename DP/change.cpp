#include <bits/stdc++.h>
using namespace std;

int change1(vector<int> &coins, int amount) {
    vector<int> dp(amount, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int change2(vector<int> &coins, int amount) {
    vector<int> dp(amount, 0);
    dp[0] = 1;
    for (int j = 1; j <= amount; j++) {
        for (int i = 0; i < coins.size(); i++) {
            if (j >= coins[i]) {
                dp[j] += dp[j - coins[i]];
            }
        }
    }
    return dp[amount];
}

int main(int argc, char const *argv[]) {
    vector<int> coins = {1, 5};
    int amount = 8;
    // cout << change1(coins, amount) << endl;
    cout << change2(coins, amount) << endl;
    return 0;
}
