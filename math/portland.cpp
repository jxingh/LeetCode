#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double calc(double a, double b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}

double toPostCalc(string str)
{
    stack<char> ops;
    stack<double> nums;
    string s = "";

    for (char c : str)
    {
        if (isdigit(c))
        {
            s += c;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (s != "")
            {
                nums.push(stod(s));
                s = "";
            }
            while (!ops.empty() && ops.top() != '(' && priority(c) <= priority(ops.top()))
            {
                double num1 = nums.top();
                nums.pop();
                double num2 = nums.top();
                nums.pop();
                nums.push(calc(num2, num1, ops.top()));
                ops.pop();
            }
            ops.push(c);
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            if (s != "")
            {
                nums.push(stod(s));
                s = "";
            }
            while (!ops.empty() && ops.top() != '(')
            {
                double num1 = nums.top();
                nums.pop();
                double num2 = nums.top();
                nums.pop();
                nums.push(calc(num2, num1, ops.top()));
                ops.pop();
            }
            ops.pop();
        }
    }
    nums.push(stod(s));
    while (!ops.empty())
    {
        double num1 = nums.top();
        nums.pop();
        double num2 = nums.top();
        nums.pop();
        nums.push(calc(num2, num1, ops.top()));
        ops.pop();
    }
    return nums.top();
}

// 10-2+3
int main()
{
    string str;
    cin >> str;
    cout << toPostCalc(str) << endl;
    return 0;
}