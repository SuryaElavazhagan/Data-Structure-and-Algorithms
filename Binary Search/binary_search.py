"""
    ************DIVIDE AND CONQUER***************
    => Get sorted elements as input
    => Compute mid element index and compare it with search key.
    => If the key is greater than mid element then search in right side
    => else search on right side
    => If the key is not found index at which it can be inserted is returned. 
"""
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

def main():
    """
        Program starts here
    """
    #num = int(input("Give n:"))
    num = int(input())

    #print("Give sorted n elements:")
    array = [int(x) for x in input().split()]
    assert(len(array) == num)

    #search_key = int(input("Give search_key:"))
    search_key = int(input())

    #print("Element is found at (or) can be inserted at:")
    print(bin_search(array, 0, num - 1, search_key))

if __name__ == "__main__":
    main()
    