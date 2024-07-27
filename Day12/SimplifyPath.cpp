// Leetcode question number 71 :
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string component;

        while (getline(ss, component, '/')) {
            if (component == "" || component == ".") {
               continue;
            } else if (component == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(component);
            }
        }

        string canonicalPath;
        for (const string& dir : stack) {
            canonicalPath += "/" + dir;
        }

        return canonicalPath.empty() ? "/" : canonicalPath;
    }
};
