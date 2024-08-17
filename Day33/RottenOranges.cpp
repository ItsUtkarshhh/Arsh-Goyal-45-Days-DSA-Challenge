// GFG Question :
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        int minutes = 0;
        
        // Add all initially rotten oranges to the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // Directions for moving in the grid (up, down, left, right)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> orange = q.front();
                q.pop();
                for (auto d : directions) {
                    int newRow = orange.first + d.first;
                    int newCol = orange.second + d.second;
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshCount--;
                    }
                }
            }
            minutes++;
        }
        
        // If there are still fresh oranges left, return -1
        return (freshCount == 0) ? minutes : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int result = sol.orangesRotting(grid);
    cout << "Minimum minutes until no fresh oranges remain: " << result << endl;
    return 0;
}
