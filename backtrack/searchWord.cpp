#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, string &word, int k, int i, int j) {
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visit[i][j] || word[k] != board[i][j]) {
        return false;
    }
    if(k == word.size() - 1) {
        return true;
    }
    visit[i][j] = true;
    if(dfs(board, visit, word, k + 1, i, j + 1) || dfs(board, visit, word, k + 1, i + 1, j) ||
       dfs(board, visit, word, k + 1, i, j - 1) || dfs(board, visit, word, k + 1, i - 1, j)) {
        return true;
    }
    visit[i][j] = false;
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(dfs(board, visit, word, 0, i, j)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}