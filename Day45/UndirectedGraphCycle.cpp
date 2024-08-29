// GFG Question :
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the parent of a node (with path compression)
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    // Function to perform union of two sets
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<pair<int, int>>& edges) {
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initializing the parent of each node to itself
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Checking for each edge if it forms a cycle
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;

            int rootU = findParent(u, parent);
            int rootV = findParent(v, parent);

            // If both nodes have the same root, a cycle is detected
            if (rootU == rootV) {
                return true;
            }

            // Otherwise, perform the union of both sets
            unionSets(u, v, parent, rank);
        }

        return false;
    }
};

int main() {
    Solution obj;
    
    int V = 5; // Number of vertices in the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0} // Adding this edge forms a cycle
    };

    if (obj.isCycle(V, edges)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
