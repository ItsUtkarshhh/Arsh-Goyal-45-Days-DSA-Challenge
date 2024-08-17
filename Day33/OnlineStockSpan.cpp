// Leetcode question number 901 :
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> s;
    int index;

    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++;
        int span = 1;

        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }

        s.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner* obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int price : prices) {
        cout << "Stock price: " << price << " -> Span: " << obj->next(price) << endl;
    }
    delete obj;
    return 0;
}
