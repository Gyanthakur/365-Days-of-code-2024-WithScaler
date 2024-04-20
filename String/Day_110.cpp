// https://www.interviewbit.com/problems/compare-version-numbers/



#include <bits/stdc++.h>
using namespace std;
int compareVersion(string A, string B)
{
    int m = A.size();
    int n = B.size();
    string curr1 = "";
    string curr2 = "";
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        while (i < m && A[i] != '.')
        {
            curr1 += A[i];
            i++;
        }
        while (j < n && B[j] != '.')
        {
            curr2 += B[j];
            j++;
        }
        int k = 0;
        int l = 0;
        // remove trailing zeros
        while (k < curr1.size() && curr1[k] == '0')
        {
            k++;
        }
        while (l < curr2.size() && curr2[l] == '0')
        {
            l++;
        }
        // check for different sizes of one bigger than its obviously larger integer
        // keep in mind we have to check the size without trailing zeros
        if (curr1.size() - k > curr2.size() - l)
        {
            return 1;
        }
        else if (curr2.size() - l > curr1.size() - k)
        {
            return -1;
        }
        // if same size check which string is bigger using elementwise comparison

        while (k < curr1.size() && l < curr2.size())
        {
            if (curr1[k] == curr2[l])
            {
                k++;
                l++;
            }
            else if (curr1[k] > curr2[l])
            {
                return 1;
            }
            else if (curr1[k] < curr2[l])
            {
                return -1;
            }
        }
        // if one remains short of the other
        if (k < curr1.size())
        {
            return 1;
        }
        else if (l < curr2.size())
        {
            return -1;
        }
        // both strings are same at this point

        if (i < m)
        { // jump from the '.'
            i++;
        }
        if (j < n)
        { // jump from the '.'
            j++;
        }
        curr1 = ""; // reset
        curr2 = "";
    }
    // if one remains short of the other one
    // beware of all zeros afterwards in bigger string, in that case they are equal still

    if (j < n)
    {
        while (j < n)
        {
            while (j < n && B[j] != '.')
            {
                if (B[j] - '0' > 0)
                {
                    return -1;
                }
                j++;
            }
            j++;
        }
        return 0;
    }

    if (i < m)
    {
        while (i < m)
        {
            while (i < m && A[i] != '.')
            {
                if (A[i] - '0' > 0)
                {
                    return 1;
                }
                i++;
            }
            i++;
        }
        return 0;
    }
    return 0;
}