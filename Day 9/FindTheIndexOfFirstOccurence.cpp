// Leetcode question number 28 :
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
        return 0;
        }

        // Find the first occurrence of needle in haystack
        size_t position = haystack.find(needle);
        
        // If needle is not found, find returns string::npos
        if (position != std::string::npos) {
            return static_cast<int>(position);
        } else {
            return -1;
        }
    }
};
