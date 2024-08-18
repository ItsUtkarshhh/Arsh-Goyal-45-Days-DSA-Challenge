// GFG Question :
#include <iostream>
#include <vector>
using namespace std;

int tour(vector<int> petrol, vector<int> distance) {
    int n = petrol.size();
    int start = 0, deficit = 0, surplus = 0;

    for (int i = 0; i < n; i++) {
        surplus += petrol[i] - distance[i];
        if (surplus < 0) {
            start = i + 1;  // Update the starting point to the next pump
            deficit += surplus;  // Accumulate the deficit
            surplus = 0;  // Reset the surplus
        }
    }
    
    // If the total surplus + deficit is non-negative, then we have a valid start
    return (surplus + deficit >= 0) ? start : -1;
}

int main() {
    // Example usage:
    vector<int> petrol = {4, 6, 7, 4};
    vector<int> distance = {6, 5, 3, 5};

    int start = tour(petrol, distance);
    if (start != -1) {
        cout << "Start at petrol pump index: " << start << endl;
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
