// Leetcode question number 733 :
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int startColor) {
        // Boundary check and if the color is different, return
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != startColor) {
            return;
        }
        
        // Change the color to newColor
        image[sr][sc] = newColor;
        
        // Recursively call DFS in all four directions
        dfs(image, sr + 1, sc, newColor, startColor); // Down
        dfs(image, sr - 1, sc, newColor, startColor); // Up
        dfs(image, sr, sc + 1, newColor, startColor); // Right
        dfs(image, sr, sc - 1, newColor, startColor); // Left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startColor = image[sr][sc];
        
        // If the starting pixel already has the newColor, no need to proceed
        if (startColor != newColor) {
            dfs(image, sr, sc, newColor, startColor);
        }
        
        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);
    
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}
