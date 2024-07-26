#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>
using namespace std;
#define int long long
long long  t;
void solution()
{

}

void callBfs(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, vector<int>&ans, int node)
{
    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        
        for(auto it : adj[frontNode])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

void prepairAdjList(unordered_map<int,list<int>>&adj, vector<pair<int,int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int>bfs(int vertex, vector<pair<int,int>>edges)
{
    unordered_map<int,bool>visited;
    vector<int>ans;
    unordered_map<int,list<int>>adj;
    prepairAdjList(adj,edges);

    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            callBfs(adj,visited,ans,i);
        }
    }
    return ans;
}












