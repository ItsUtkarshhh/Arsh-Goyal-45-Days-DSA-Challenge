// GFG Question :
def findPages(n, arr, m):
    def canAllocate(maxPages):
        studentCount = 1
        currentSum = 0
        for pages in arr:
            if currentSum + pages > maxPages:
                studentCount += 1
                currentSum = pages
                if studentCount > m:
                    return False
            else:
                currentSum += pages
        return True

    if m > n:
        return -1
