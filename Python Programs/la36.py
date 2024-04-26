# Write a python function for merge/quick sort for integer list as parameter to it.

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

# Example usage:
arr=list(map(int,input("Enter the list: ").split()))

print(quick_sort(arr))
