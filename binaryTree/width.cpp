#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 不考虑空结点
int getWidth(TreeNode *root)
{
    int width = 0;
    queue<TreeNode *> q;
    if (root != NULL)
        q.push(root);
    while (!q.empty())
    {
        int len = q.size(); // 本层宽度
        for (int i = 0; i < len; ++i)
        {
            TreeNode *p = q.front();
            q.pop();
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
        width = max(len, width);
    }
    return width;
}

// 考虑空结点（leetcode 662）
int widthOfBinaryTree(TreeNode *root)
{
    unsigned long long width = 0;
    queue<pair<TreeNode *, unsigned long long>> q;
    if (root != NULL)
        q.push({root, 1});
    while (!q.empty())
    {
        int len = q.size();
        unsigned long long l = 0, r = 0;
        for (int i = 0; i < len; ++i)
        {
            pair<TreeNode *, unsigned long long> p = q.front();
            q.pop();
            if (p.first->left != NULL)
                q.push({p.first->left, 2 * p.second});
            if (p.first->right != NULL)
                q.push({p.first->right, 2 * p.second + 1});
            if (i == 0)
                l = p.second;
            if (i == len - 1)
                r = p.second;
        }
        width = max(width, r - l + 1);
    }
    return width;
}