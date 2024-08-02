// Leetcode question number 168 :
class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string title;
        
        while (columnNumber > 0) {
            // Adjust columnNumber to be zero-indexed for easier calculation
            columnNumber--;
            
            // Get the remainder when dividing by 26, which gives us the current letter
            int remainder = columnNumber % 26;
            
            // Convert the remainder to the corresponding letter ('A' is 65 in ASCII)
            char letter = 'A' + remainder;
            
            // Prepend the letter to the result
            title = letter + title;
            
            // Move to the next place value by dividing columnNumber by 26
            columnNumber /= 26;
        }
        
        return title;
    }
};
