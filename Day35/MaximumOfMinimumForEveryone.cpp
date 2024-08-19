// GFG Question :
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> maxOfMin(int arr[], int n) {
    vector<int> left(n), right(n);
    stack<int> s;

    // Fill elements of left[]
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for re-use
    while (!s.empty()) {
        s.pop();
    }

    // Fill elements of right[]
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Initialize the answer array
    vector<int> ans(n + 1, 0);

    // Fill answer array by comparing minimums of every window size
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }

    // Some entries in ans[] may not be filled, fill them by taking max of previous values
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    // Return the required array
    vector<int> result(ans.begin() + 1, ans.end());
    return result;
}

int main() {
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> res = maxOfMin(arr, n);

    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}
