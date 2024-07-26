#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;









/*

output 
4 -> [5 , -2], 
0 -> [1 , 5], [2 , 3],
1 -> [2 , 2], [3 , 6],
2 -> [3 , 7], [4 , 4], [5 , 2],
3 -> [4 , -1],
answer is :
2147483647 0 2 6 5 3

*/







// sortest path in directed acyclic graph

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    // unordered_map<u <list< node , distance>>> adj

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << "[" << j.first << " , " << j.second << "], ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = 1;

        for (auto neigbour : adj[node])
        {
            if (!visited[neigbour.first])
            {
                dfs(neigbour.first, visited, topo);
            }
        }
        topo.push(node);
    }

    void getShortesPath(int src, vector<int>&dist, stack<int>&topo)
    {
        dist[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            if(dist[top] != INT_MAX)
            {
                for(auto i: adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
        
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6;
    // topological sort

    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MAX;
    }
   g.getShortesPath(src,dist,s);

   cout<< "answer is : " << endl;

   for(int i=0;i<dist.size();i++)
   {
        cout<<dist[i] << " ";
   }
   cout<<endl;

}