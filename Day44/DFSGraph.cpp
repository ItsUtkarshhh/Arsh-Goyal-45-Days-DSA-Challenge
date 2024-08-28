// GFG Question :
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Utility function to perform DFS
    void dfs(int node, vector<int>& visited, vector<int> adj[], vector<int>& dfsResult) {
        // Mark the current node as visited
        visited[node] = 1;
        dfsResult.push_back(node);
        
        // Recur for all adjacent vertices
        for (int adjacentNode : adj[node]) {
            if (!visited[adjacentNode]) {
                dfs(adjacentNode, visited, adj, dfsResult);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfsResult;
        vector<int> visited(V, 0); // Initialize visited array
        
        // Call the recursive helper function to perform DFS traversal starting from node 0
        dfs(0, visited, adj, dfsResult);
        
        return dfsResult;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list for the graph
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    
    Solution obj;
    vector<int> result = obj.dfsOfGraph(V, adj);
    
    for(int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
