// https://www.interviewbit.com/problems/justified-text/


#include <bits/stdc++.h>
using namespace std;
string setting(vector<string> A, int last, int id, int B, int cnt)
{
    string temp = "";
    if (id == last)
    {
        int left = B - A[id].length();
        temp += A[id];
        while (left--)
        {
            temp += " ";
        }
        return temp;
    }
    int blocks = id - last;
    cnt -= blocks;
    int left = B - cnt;
    int ext = left % blocks;
    int curr = left / blocks;
    for (int i = last; i <= id; i++)
    {
        temp += A[i];
        if (i != id)
        {
            for (int j = 0; j < curr; j++)
            {
                temp += " ";
            }
            if (ext)
            {
                temp += " ";
                ext--;
            }
        }
    }
    return temp;
}
vector<string> Solution::fullJustify(vector<string> &A, int B)
{
    int cnt = 0;
    int last = 0;
    vector<string> ans;
    string temp = "";
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        cnt += A[i].length() + 1;
        temp += A[i] + " ";
        if (cnt - 1 == B)
        {
            temp.pop_back();
            ans.push_back(temp);
            temp = "";
            cnt = 0;
            last = i + 1;
        }
        else if (cnt - 1 > B)
        {
            temp = setting(A, last, i - 1, B, cnt - 2 - A[i].length());
            ans.push_back(temp);
            i--;
            temp = "";
            last = i + 1;
            cnt = 0;
        }
        else if (i == n - 1)
        {
            while (cnt < B)
            {
                temp += " ";
                cnt++;
            }
            ans.push_back(temp);
        }
    }
    return ans;
}