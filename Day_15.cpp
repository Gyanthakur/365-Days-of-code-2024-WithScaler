/* https://www.interviewbit.com/problems/largest-number/ */


#include<bits/stdc++.h>
using namespace std;
bool compareNum(string a, string b) {
    return a + b > b + a;
}
string largestNumber(const vector < int > & A) {
    string result;
    vector < string > str;
    for (int i = 0; i < A.size(); i++) {
        str.push_back(to_string(A[i]));
    }
    sort(str.begin(), str.end(), compareNum);
    for (int i = 0; i < str.size(); i++) {
        result += str[i];
    }

    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) pos++;
    return result.substr(pos);
}