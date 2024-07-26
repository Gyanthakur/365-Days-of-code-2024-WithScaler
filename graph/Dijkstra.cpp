#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;


vector<int> dijkstra(vector<vector<int>> & vec, int vertices, int edges, int src)
{
    // create adj 
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(vertices);
    // creation distance array with initialize INFINITY distance 
    for(int i=0;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int,int>>s;

    // set<pair<dist,node>>  hm set se vo vala element phle nikalenge jiski distance kam hogi 

    dist[src] = 0;
    s.insert(make_pair(0,src));


    while(!s.empty())
    {
        // fetch top record 

        auto top = *(s.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove top record from set 

        s.erase(s.begin());



        // traverse on neighbours 

        for(auto neighbor : adj[topNode])
        {
            if(nodeDistance + neighbor.second < dist[neighbor.first])
            {
                auto record = s.find(make_pair(dist[neighbor.first], neighbor.first));

                // if record found then erase it
                if(record != s.end())
                {
                    s.erase(record);
                }

                // distance update 
                dist[neighbor.first] = nodeDistance + neighbor.second ;

                // recrd push in set 
                s.insert(make_pair(dist[neighbor.first] , neighbor.first));

            }
        }
    }
    return dist;
}