// https://www.interviewbit.com/problems/evaluate-expression/

#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &A)
{

    int n = A.size();

    stack<int> st;

    for (int i = 0; i < n; i++)
    {

        if (A[i] != "+" && A[i] != "-" && A[i] != "*" && A[i] != "/")
        {

            // We are given A as string but stack has int value

            st.push(stoi(A[i])); // convert string from A to int in stack
        }

        else if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {

            int a = st.top();

            st.pop();

            int b = st.top();

            st.pop();

            if (A[i] == "+")

                st.push(a + b);

            else if (A[i] == "-")

                st.push(b - a);

            else if (A[i] == "*")

                st.push(a * b);

            else if (A[i] == "/")

                st.push(b / a);
        }
    }

    return st.top();
}