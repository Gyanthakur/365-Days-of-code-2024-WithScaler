// https://www.interviewbit.com/problems/generate-all-parentheses/

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int isValid(string A)
{
    stack<char> s;

    for (int i = 0; i < (int)A.length(); i++)
    {
        if (A[i] == '(' || A[i] == '[' || A[i] == '{')
        {
            s.push(A[i]);
        }
        else
        {
            if (!s.empty())
            {
                if (A[i] == ')')
                {
                    if (s.top() != '(')
                        return 0;
                    else
                    {
                        s.pop();
                    }
                }
                if (A[i] == '}')
                {
                    if (s.top() != '{')
                        return 0;
                    else
                    {
                        s.pop();
                    }
                }
                if (A[i] == ']')
                {
                    if (s.top() != '[')
                        return 0;
                    else
                    {
                        s.pop();
                    }
                }
            }
            else
                return 0;
        }
    }
    if (s.empty())
    {
        return 1;
    }
    return 0;
}