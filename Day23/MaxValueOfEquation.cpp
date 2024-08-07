// Leetcode question number 1499 :
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            priority_queue<int> pq;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] - points[i][0] > k) break;
                pq.push(points[j][1] + points[i][1] + points[j][0] - points[i][0]);
                if (pq.size() > k) pq.pop();
            }
            while (!pq.empty()) {
                res = max(res, pq.top());
                pq.pop();
            }
        }
        return res;
    }
};
