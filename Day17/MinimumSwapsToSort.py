# GFG Question :
def minSwaps(nums):
    n = len(nums)
  
    arr = [(num, i) for i, num in enumerate(nums)]
    
    arr.sort()
    
    # Create a visited array to track whether an element has been visited
    visited = [False] * n
    
    # Initialize the count of swaps
    swaps = 0
    
    for i in range(n):
        # If the element is already in the correct position or already visited
        if visited[i] or arr[i][1] == i:
            continue
        
        # Compute the size of the cycle
        cycle_size = 0
        x = i
        
        while not visited[x]:
            visited[x] = True
            x = arr[x][1]
            cycle_size += 1
        
        # If there is a cycle of size cycle_size, it requires (cycle_size - 1) swaps
        if cycle_size > 0:
            swaps += (cycle_size - 1)
    
    return swaps
