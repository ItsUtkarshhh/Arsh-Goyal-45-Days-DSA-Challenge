// Leetcode question number 121 :
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int price : prices) {
            minPrice = min(minPrice,price);
            int potentialProfit = price - minPrice;
            maxProfit = max(potentialProfit,maxProfit);
        }
        return maxProfit;
    }
};
