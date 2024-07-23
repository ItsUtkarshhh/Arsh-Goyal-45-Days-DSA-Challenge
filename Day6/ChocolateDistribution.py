# GFG Question :
def findMinDiff(self, A, N, M):
    if M == 0 or N == 0:
        return 0
    
    # Sort the array
    A.sort()
    
    # Number of students cannot be more than number of packets
    if N < M:
        return -1
    
    # Find the minimum difference
    min_diff = float('inf')
    
    # Find the minimum difference between the maximum and minimum of M packets
    for i in range(N - M + 1):
        diff = A[i + M - 1] - A[i]
        if diff < min_diff:
            min_diff = diff
    
    return min_diff
