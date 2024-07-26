#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>

using namespace std;



int detectCycleInDirectedGraph(int v, vector<pair<int,int>>&edges)
{
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }
    //  find all indegrees of all nodes

    vector<int>indegree(v,0);
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    // 0 indegree valo ko q me push kr do 
    queue<int>q;
    for(int i=1;i<=v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs 
    vector<int>ans;
    int cnt = 0;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store 
        // ans.push_back(front);

        cnt++;

        // neighbour indegree update 

        for(auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    // return ans;
    if(cnt == v)   // valid topological sort hai
        return false; // cycle present nahi hai
    return true; //cycle present hai
}