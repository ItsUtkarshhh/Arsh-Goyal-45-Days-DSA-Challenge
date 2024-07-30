// SPOJ.com Question :
#include <iostream>
#include <algorithm>
#include <vector>  // Added to use vectors
using namespace std;

bool isPossible(vector<int>& stalls, int cows, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0]; // It tells the first cow kahaa rakhi hai, here last is not LAST, its like abhi jo last cow rakhi thi vo kahaa rakhi thi, toh vo first stall pr rakhi thi and that is represented as stall[0]
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            if (cowCount == cows) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back();  // Use the maximum element as the end point
    int ans = -1;
    int mid;
    while (s <= e) {
        mid = s + (e - s) / 2;
        if (isPossible(stalls, cows, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;

    vector<int> stalls(size);
    for (int i = 0; i < size; i++) {
        cin >> stalls[i];
    }

    int cows; // Number of cows!
    cin >> cows;

    int result = aggressiveCows(stalls, cows);
    cout << result << endl;

    return 0;
}
