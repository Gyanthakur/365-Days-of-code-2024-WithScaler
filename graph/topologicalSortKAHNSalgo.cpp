#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
#include<math.h>
#include<set>

using namespace std;

/*

    kahn's algorithm 
    3 step 
    1. fornd indegree of all nodes 
    2. 0 indegree valo ko q me push kro
    3. bfs perform kro


*/

vector<int>topologicalSort(vector<vector<int>>&edges, int v, int e)
{
    // create adj list 

    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

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
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // do bfs 
    vector<int>ans;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store 
        ans.push_back(front);

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
    return ans;
}