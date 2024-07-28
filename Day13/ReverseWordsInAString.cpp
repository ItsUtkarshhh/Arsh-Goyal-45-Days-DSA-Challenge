// Leetcode question number 151 :
class Solution {
public:
    string reverseWords(string s) {
        trim(s);
        
        std::vector<std::string> words = split(s);
        
        std::reverse(words.begin(), words.end());
        
        return join(words);
    }
    
    private:
        void trim(std::string& s) {
            size_t start = s.find_first_not_of(' ');
            size_t end = s.find_last_not_of(' ');
            if (start == std::string::npos) {
                s = "";
            } else {
                s = s.substr(start, end - start + 1);
            }
        }
        
        std::vector<std::string> split(const std::string& s) {
            std::vector<std::string> words;
            std::istringstream stream(s);
            std::string word;
            while (stream >> word) {
                words.push_back(word);
            }
            return words;
        }
        
        std::string join(const std::vector<std::string>& words) {
            std::string result;
            for (size_t i = 0; i < words.size(); ++i) {
                if (i > 0) {
                    result += " ";
                }
                result += words[i];
            }
        return result;
    }
};
