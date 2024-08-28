// Leetcode question number 200 :
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Boundary check and if the current cell is water ('0'), just return
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
            return;
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Explore all 4 possible directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        
        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Traverse through the entire grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If we encounter land ('1'), it indicates a new island
                if (grid[i][j] == '1') {
                    ++numIslands;
                    dfs(grid, i, j); // Mark all connected lands
                }
            }
        }
        
        return numIslands;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    
    int result = sol.numIslands(grid);
    cout << "Number of islands: " << result << endl;
    
    return 0;
}
