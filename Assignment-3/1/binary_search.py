def bin_search(array, low, high, search_key):
    """
        Actual logic goes here
    """
    if high < low:
        return low
    """
        (low + high) / 2 => may be float
        > It is type casted to integer
    """
    mid = int((low + high) / 2)
    """
        * If the element is present, finally the element will be in the mid
    """
    if array[mid] == search_key:
        return mid
    # Search on right side
    elif array[mid] < search_key:
        return bin_search(array, mid + 1, high, search_key)
    # Search on left side
    else:
        return bin_search(array, low, mid - 1, search_key)

def binary_search(array, search_keys, n, k):
    """
        For each elements in the search keys array 
        Binary search is called.
    """
    temp_index = 0
    while temp_index < k:
        print(bin_search(array, 0, n - 1, search_keys[temp_index]) , " ", end = "")
        temp_index += 1

def main():
    """
        Program starts here
    """

    #print("Give n and n elements:")
    first_line = [int(x) for x in input().split()]
    
    #print("Give k and k search elements:")
    second_line = [int(x) for x in input().split()]

    # Separating
    n = first_line[0]
    
    # list[x:] => means it outputs the elements from index x
    array = first_line[1:]

    # checking 
    assert(n == len(array))

    # Same applies here.
    k = second_line[0]
    search_keys = second_line[1:]
    assert(k == len(search_keys))
    binary_search(array, search_keys, n, k)

if __name__ == "__main__":
    main()
