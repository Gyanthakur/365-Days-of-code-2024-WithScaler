/* https://www.interviewbit.com/problems/reverse-string/ */

#include <bits/stdc++.h>
using namespace std;
string reverseString(string A) {
    reverse(begin(A),end(A));
    return A;
}
