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



bool isCycleBfs(int src, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited)
{
    unordered_map<int,int>parent;
    parent[src] = -1;
    visited[src] = 1;


    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour: adj[frontNode])
        {
            if(visited[neighbour] == 1 && neighbour != parent[frontNode])
            {
                return 1;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return 0;
}




string cucleDetection(vector<vector<int>>&edges, int n, int m)
{
    // m edges 
    // vertex from 1 to n 

    // create adjlist 


    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool>visited;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleBfs(i, adj, visited);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}















signed main()
{
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
cin>>t;
while(t--)
{
solution();
cout<<endl;
}
return 0;
}