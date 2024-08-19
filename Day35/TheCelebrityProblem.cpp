// GFG Question :
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to find the celebrity
    int celebrity(vector<vector<int> >& M, int n) {
        int candidate = 0;
        
        // Step 1: Find a potential candidate
        for (int i = 1; i < n; ++i) {
            if (M[candidate][i] == 1) {
                // candidate knows i, so candidate cannot be a celebrity
                candidate = i;
            }
        }
        
        // Step 2: Verify the candidate
        for (int i = 0; i < n; ++i) {
            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                return -1; // candidate knows someone, or not everyone knows candidate
            }
        }
        
        return candidate; // candidate is the celebrity
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};
    
    int n = M.size();
    int result = sol.celebrity(M, n);
    
    if (result == -1) {
        cout << "No celebrity" << endl;
    } else {
        cout << "Celebrity is at index: " << result << endl;
    }
    
    return 0;
}
