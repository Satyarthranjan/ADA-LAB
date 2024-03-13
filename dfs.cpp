#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std
class Network
{
    int n;
    vector<vector<int>> adj;
public:
    Network(int numSystems) : n(numSystems)
    {
        adj.resize(n);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void DFS(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << start << " ";
        for (int u : adj[start])
        {
            if (!visited[u])
            {
                DFS(u, visited);
            }
        }
    }
    void findReachableSystems(int start)
    {
        vector<bool> visited(n, false); // Array to mark visited systems
        cout << "Systems reachable from system " << start << ": ";
        DFS(start, visited);
        cout << endl;
    }
};
int main()
{
    int numSystems = 6; // Number of systems in the network
    Network network(numSystems);
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(1, 4);
    network.addEdge(2, 4);
    network.addEdge(3, 5);
    network.addEdge(4, 5);
    int startSystem = 0; // Choose the starting system for DFS traversal
    clock_t start,end;
    start=clock();
    network.findReachableSystems(startSystem);
    end=clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    cout<<"\ntime spent: "<<time_spent;
    return 0;
}
