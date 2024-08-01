# GFG Question :
def missingNumber(arr, n):
    for i in range(n):
        while 1 <= arr[i] <= n and arr[i] != arr[arr[i] - 1]:
            arr[i], arr[arr[i] - 1] = arr[arr[i] - 1], arr[i]

    for i in range(n):
        if arr[i] != i + 1:
            return i + 1
    return n + 1
