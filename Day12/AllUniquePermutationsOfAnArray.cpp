// GFG Question :
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(), arr.end());
    
    // Set to store unique permutations
        set<vector<int>> uniquePermutations;
        
        // Generate permutations
        do {
            uniquePermutations.insert(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        
        // Convert the set to a vector
        vector<vector<int>> result(uniquePermutations.begin(), uniquePermutations.end());
    
    return result;
    }
};
