#include <bits/stdc++.h>
using namespace std;

const int MONEY = 1023;
const int VALUE = 5;
int type[VALUE] = {1, 5, 10, 20, 50};
int Min[MONEY];
int Min_path[MONEY] = {0};

void solve()
{
    for (int i = 0; i < MONEY; i++)
    {
        Min[i] = INT_MAX;
    }
    Min[0] = 0;
    for (int i = 0; i < VALUE; i++)
    {
        for (int j = type[i]; j < MONEY; j++)
        {
            if (Min[j] > Min[j - type[i]] + 1)
            {

                Min_path[j] = type[i];
                Min[j] = Min[j - type[i]] + 1;
            }
        }
    }
}

void print_ans(int *Min_path, int s)
{
    while (s)
    {
        cout << Min_path[s] << " ";
        s = s - Min_path[s];
    }
}

int main()
{
    int s;
    solve();
    while (cin >> s)
    {
        cout << "Min[" << s << "]= " << Min[s] << endl;
        print_ans(Min_path, s);
    }
    return 0;
}