// #include <iostream>
// #include <list>
// #include <unordered_map>

// using namespace std;


// class graph
// {

// public:
//     unordered_map<int, list<int>> adj;
//     void addEdge(int u, int v, bool direction)
//     {
//         // direction = 0 -> undirected graph
//         // direction = 1 -> directed graph

//         // create an edge from u to v
//         adj[u].push_back(v);

//         if (direction == 0)
//         {
//             adj[v].push_back(u);
//         }
//     }

//     void printAdjList()
//     {
//         for (auto i : adj)
//         {
//             cout << i.first << "->";
//             for (auto j : i.second)
//             {
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     int n;
//     cout << "enter the number of edges : " << endl;
//     cin >> n;
//     int m;
//     cout << "Enter the number of edges : " << endl;
//     cin >> m;
//     graph g;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         // enter nodes
//         cin >> u >> v;
//         g.addEdge(u, v, 0);
//     }
//     g.printAdjList();
// }





// genric graph using template 



#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
template <typename T>

class graph
{

public:
    unordered_map<T, list<T>> adj;
    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "enter the number of edges : " << endl;
    cin >> n;
    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;
    graph<int> g; // we create any type of graph like char, string just write as  "graph<string>g"
    for (int i = 0; i < m; i++)
    {
        int u, v;
        // enter nodes
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();
}