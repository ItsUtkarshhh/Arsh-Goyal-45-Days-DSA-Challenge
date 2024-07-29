// GFG question :
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        unordered_map<string, vector<string>> anagram_map;

    // Iterate through each string in the input list
    for (const string& str : string_list) {
        // Sort the string
        string sorted_str = str;
        sort(sorted_str.begin(), sorted_str.end());

        // Add the original string to the map using the sorted string as the key
        anagram_map[sorted_str].push_back(str);
    }

    // Collect the groups of anagrams from the hash map
    vector<vector<string>> result;
    for (const auto& entry : anagram_map) {
        result.push_back(entry.second);
    }

    return result;
    }
};
