"""
    *************DIVIDE AND CONQUER**************
    * Divide array into 2
    * Merge the 2 array
    ******************MERGING********************
    * Compare each elements from two half of the array
      from left to right and insert the least to a temp array
    * At last any of the two half will be empty
    * Put all the elements from the non-empty array to temp array
    * Return temp.
"""

def merge(arr, low, high, mid):
    """
        Actual logic goes here.
    """
    left_index = 0
    right_index = 0
    temp_index = low

    left_size = mid - low + 1
    right_size = high - mid

    left_half = list()
    right_half = list()

    # Inserting left half to left temporary array
    for i in range(0, left_size):
        left_half.append(arr[i + low])
    
    # Inserting right half to right temporary array
    for i in range(0, right_size):
        right_half.append(arr[mid + 1 + i])
    
    # Comparing and storing to temporary array
    while left_index < left_size and right_index < right_size:
        if left_half[left_index] <= right_half[right_index]:
            arr[temp_index] = left_half[left_index]
            left_index += 1
        else:
            arr[temp_index] = right_half[right_index]
            right_index += 1
        temp_index += 1
    
    # Copying the remaining elements
    while left_index < left_size:
        arr[temp_index] = left_half[left_index]
        temp_index += 1
        left_index += 1
    
    while right_index < right_size:
        arr[temp_index] = right_half[right_index]
        temp_index += 1
        right_index += 1

def merge_sort(arr, low, high):
    """
        Separating is done here.
    """
    if low < high:
        mid = int((low + high) / 2)
        
        # Left half
        merge_sort(arr, low, mid)
        
        # Right half
        merge_sort(arr, mid + 1, high)
        
        # Joining two halves
        merge(arr, low, high, mid)

def main():
    """
        Program starts here.
    """
    #num = int(input("Give n:"))
    num = int(input())

    #print("Give n elements:")
    arr = [int(x) for x in input().split()]
    merge_sort(arr, 0, num - 1)

    #print("Sorted list:")
    print(arr)

if __name__ == "__main__":
    main()
    