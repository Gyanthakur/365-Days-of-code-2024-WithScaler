#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;

/*

    1. prepaire adj list
    2. create visites array and parente arrey
    3. do bfs
    4. do while loop untill destination != source and store it on ans variable 
    5. reverse ans 

*/



vector<int> shortestPath(vector<pair<int, int>> &edges, int n, int m, int s, int t)
{
    // n = number of vertex
    // m = number of edges
    // s = source vertex
    // t = destination vertex

    // create adj

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    // do bfs 
    unordered_map<int,bool>visited;
    unordered_map<int,bool>parent;

    queue<int>q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbor : adj[front])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = 1;
                parent[neighbor] = front;
                q.push(neighbor);
            }
        }
    }
    

    // prepaire shortest path 

    vector<int>ans;

    int currNode = t;
    ans.push_back(t);
    while(currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}