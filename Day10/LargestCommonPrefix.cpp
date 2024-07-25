// Leetcode question number 14 :
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Sort the array
        std::sort(strs.begin(), strs.end());

        // Take the first and the last string
        std::string first = strs[0];
        std::string last = strs[strs.size() - 1];
        int i = 0;
        
        // Compare characters one by one
        while (i < first.size() && first[i] == last[i]) {
            i++;
        } 
    return first.substr(0, i);
    }
};
