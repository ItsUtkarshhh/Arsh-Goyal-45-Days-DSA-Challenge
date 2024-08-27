// Leetcode question number 96 :
#include <iostream>
#include <vector>

class Solution {
public:
    int numTrees(int n) {
        // Vector to store the number of unique BSTs for each number of nodes
        std::vector<int> dp(n + 1, 0);

        // There is 1 unique BST with 0 nodes (empty tree)
        // There is 1 unique BST with 1 node
        dp[0] = 1;
        dp[1] = 1;

        // Fill the dp array
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // For each i, consider j as the root
                // The left subtree has j-1 nodes
                // The right subtree has i-j nodes
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        // The answer is the number of unique BSTs that can be formed with n nodes
        return dp[n];
    }
};
