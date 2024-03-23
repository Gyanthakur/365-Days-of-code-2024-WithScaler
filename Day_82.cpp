// https://interviewbit.com/problems/simplify-directory-path/



#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path)
{
    vector<string> s;
    string temp;

    int i = 0;
    while (i < path.size())
    {
        if (path[i] == '/')
        {
            i++;
            continue;
        }

        while (i < path.size() && path[i] != '/')
            temp.push_back(path[i++]);

        if (temp == ".." && !s.empty())
            s.pop_back();
        else if (temp != "." && temp != "..")
            s.push_back(temp);
        temp.clear();
        i++;
    }

    string ans = "";

    for (auto i : s)
    {
        ans.push_back('/');
        ans.append(i);
    }
    if (ans.size() == 0)
        return "/";
    return ans;
}