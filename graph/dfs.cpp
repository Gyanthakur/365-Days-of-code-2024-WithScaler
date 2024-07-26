#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>
using namespace std;
#define int long long
long long t;
void solution()
{
}


void dfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int node, vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            dfs(adj,visited, i, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(adj,visited,i,component);
            ans.push_back(component);
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}