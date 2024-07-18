// GFG Question :
bool isPossible(long long a[], long long b[], int n, long long k) {
    // Sort array a in ascending order
    sort(a, a + n);
    
    // Sort array b in descending order
    sort(b, b + n, greater<long long>());
    
    // Check if the condition a[i] + b[i] >= k holds for all i
    for (int i = 0; i < n; ++i) {
        if (a[i] + b[i] < k) {
            return false;
        }
    }
    
    return true;
}
