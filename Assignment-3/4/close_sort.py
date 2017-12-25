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

def merge(arr, low, high, mid, left_inversion, right_inversion):
    """
        Actual logic goes here.
    """
    inversion = left_inversion + right_inversion;
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
            """
            **************** Important **********************
             * If the right half contains smaller element than the
             * left half then the right element is lesser than
             * all the elements from left_index
             * For eg.,
             *  left half = 2 5 6 8 9
             *  right half = 4 7 10 11
             * Consider '4' from right half
             * It is greater than 2 then left_index is incremented.
             * Now '4' is lesser than 5
             * It is lesser than 5,6,8,9
             * So it takes 4 Inversions.
            """
            inversion += left_size - left_index
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
    return inversion

def merge_sort(arr, low, high):
    """
        Separating is done here.
    """
    left_inversion = 0
    right_inversion = 0
    if low < high:
        mid = int((low + high) / 2)
        
        # Left half
        left_inversion = merge_sort(arr, low, mid)
        
        # Right half
        left_inversion = merge_sort(arr, mid + 1, high)
        
        # Joining two halves
        return merge(arr, low, high, mid, left_inversion, right_inversion)
    return 0

def main():
    n = int(input())
    
    array = [int(x) for x in input().split()]
    assert(len(array) == n)
    if n <= 2:
        print("0")
    else:
        print(merge_sort(array, 0, n -1))

if __name__ == "__main__":
    main()