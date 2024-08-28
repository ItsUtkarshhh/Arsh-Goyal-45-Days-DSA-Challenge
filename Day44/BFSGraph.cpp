// GFG Question :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsResult; // To store the BFS traversal result.
        vector<bool> visited(V, false); // To keep track of visited nodes.
        
        queue<int> q; // Queue for BFS traversal.
        
        // Start BFS from the first node (assuming 0 is the starting point).
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfsResult.push_back(node);
            
            // Visit all the adjacent vertices of the current node.
            for(int adjacentNode : adj[node]) {
                if(!visited[adjacentNode]) {
                    q.push(adjacentNode);
                    visited[adjacentNode] = true;
                }
            }
        }
        
        return bfsResult;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V]; // Adjacency list for the graph
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    
    Solution obj;
    vector<int> result = obj.bfsOfGraph(V, adj);
    
    for(int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
