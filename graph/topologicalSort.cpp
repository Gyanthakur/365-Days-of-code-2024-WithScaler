#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>

using namespace std;

void toposort(int node,vector<bool>&visited,unordered_map<int,list<int>>&adj,stack<int>&s)
{
    visited[node] = 1;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            toposort(neighbour,visited,adj,s);
        }
    }
    s.push(node);
}


vector<int>topologicalSort(vector<vector<int>>&edges, int v, int e)
{
    // topological short is valid for directed acyclic graph (dag)
    // create adj list

    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topologicalsort utill function for all components 
    // unordered_map<int,bool>visited;   // give tle so we are use vector insteat of map
    vector<bool>visited(v,false);
    stack<int>s;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            toposort(i,visited,adj,s);
        }
    }

    vector<int>ans;

    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}