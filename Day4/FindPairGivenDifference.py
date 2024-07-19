# GFG Question :
def findPair(self, n: int, x: int, arr: List[int]) -> int:
        # Sort the array
        arr.sort()
        
        # Initialize two pointers
        left = 0
        right = 1
        
        # Iterate through the array with two pointers
        while right < n:
            # Calculate the absolute difference
            diff = abs(arr[right] - arr[left])
            
            if diff == x:
                return 1
            elif diff < x:
                right += 1
            else:
                if left == right - 1:
                    right += 1
                left += 1
        
        return -1
