// https://www.interviewbit.com/problems/pretty-json/


#include <bits/stdc++.h>
using namespace std;
string insertTab(int tab){
    string ans;
    for(int i = 0; i < tab; ++i) ans += "\t";
    return ans;
}
vector<string> prettyJSON(string A) {
    if(A == "") return {};
    vector<string> ans;
    string k = "";
    int tab = 0;
    for(char c : A){
        if(c=='{' || c=='['){
            if(k != "") ans.push_back(insertTab(tab) + k);
            ans.push_back(insertTab(tab) + c);
            ++tab;
            k = "";
        }
        else if(c=='}' || c==']'){
            if(k != "") ans.push_back(insertTab(tab) + k);
            --tab;
            k = c;
        } 
        else if(c==','){
            k += c;
            ans.push_back(insertTab(tab) + k);
            k = "";
        }
        else{
            k += c;
        }
    }
    if(k!="")    ans.push_back(k);
    return ans;
}