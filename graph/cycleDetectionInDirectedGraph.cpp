#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>

using namespace std;





bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int,list<int>>&adj)
{
    visited[node] = 1;
    dfsvisited[node] = 1;
    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycledetected = checkCycleDfs(neighbour, visited, dfsvisited, adj);
            if(cycledetected)
                return true;
        }
        else if(visited[neighbour] && dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>>&edges)
{
    unordered_map<int,list<int>>adj;

    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycleDfs(i,visited,dfsvisited,adj);
            if(cycleFound)
                return true;
        }
    }
    return false;
}

















