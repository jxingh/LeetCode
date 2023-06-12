#include <bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings)
{
    int len = ratings.size();
    vector<int> candies(len, 1);
    for (int i = 0; i < len - 1; i++)
    {
        if (ratings[i + 1] > ratings[i] && candies[i + 1] <= candies[i])
        {
            candies[i + 1] = candies[i] + 1;
        }
    }
    int sum = candies[len - 1];
    for (int i = len - 1; i > 0; i--)
    {
        if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i])
        {
            candies[i - 1] = candies[i] + 1;
        }
        sum += candies[i - 1];
    }
    return sum;
}