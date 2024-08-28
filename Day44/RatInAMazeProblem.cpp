// GFG Question :
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& m, int n, int x, int y, vector<vector<bool>>& visited, string path, vector<string>& result) {
        // Base condition: If we've reached the bottom-right corner
        if (x == n - 1 && y == n - 1) {
            result.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = true;
        
        // Possible directions and corresponding characters
        string directions = "DLRU"; // Down, Left, Right, Up
        int rowMove[] = {1, 0, 0, -1}; // Change in row for D, L, R, U
        int colMove[] = {0, -1, 1, 0}; // Change in column for D, L, R, U
        
        // Explore all possible directions
        for (int i = 0; i < 4; ++i) {
            int nextX = x + rowMove[i];
            int nextY = y + colMove[i];
            
            // Check if the move is valid
            if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n && m[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                dfs(m, n, nextX, nextY, visited, path + directions[i], result);
            }
        }

        // Backtrack: Unmark the current cell as visited
        visited[x][y] = false;
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> result;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start DFS from the top-left corner
        if (m[0][0] == 1) {
            dfs(m, n, 0, 0, visited, "", result);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> m = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = m.size();
    vector<string> result = obj.findPath(m, n);

    for (const string& path : result) {
        cout << path << " ";
    }

    return 0;
}
