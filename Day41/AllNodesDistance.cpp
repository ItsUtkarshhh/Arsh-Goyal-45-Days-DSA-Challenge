// Leetcode question number 863 :
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // To store the parent of each node
        unordered_map<TreeNode*, TreeNode*> parentMap;
        // Record parents of all nodes
        recordParents(root, nullptr, parentMap);

        // BFS to find all nodes at distance K from the target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (currentLevel == K) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            currentLevel++;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Explore the left child
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Explore the right child
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Explore the parent
                if (parentMap[node] && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
        }

        // If no nodes are found at distance K, return an empty vector
        return {};
    }

private:
    // Helper function to record parents of each node
    void recordParents(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!node) return;
        parentMap[node] = parent;
        recordParents(node->left, node, parentMap);
        recordParents(node->right, node, parentMap);
    }
};
