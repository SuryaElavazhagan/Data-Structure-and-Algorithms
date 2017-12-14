"""
    * This sorting is done when the array is filled with a range of numbers
"""
def count_sort(arr, no_of_elements, max_number):
    """
        Actual logic goes here.
    """

    # Counts each element
    count = [0 for i in range(0, max_number + 1)]
    for i in range(0 , no_of_elements):
        count[arr[i]] += 1
    
    # Stores position of each element based on count
    position = [0 for i in range(0, max_number + 1)]
    position[0] = 0
    for i in range(1, max_number + 1):
        position[i] = position[i - 1] + count[i - 1]
    
    # Array is filled here
    list_sorted = [0 for i in range(0, no_of_elements)]
    for i in range(0, no_of_elements):
        list_sorted[position[arr[i]]] = arr[i]
        position[arr[i]] += 1
    return list_sorted

def main():
    """
        Program starts here
    """
    """
    no_of_elements = int(input("Give n:"))
    max_number = int(input("Give max range:"))
    """
    no_of_elements = int(input())
    max_number = int(input())

    #print("Give array of n numbers:")
    arr = [int(x) for x in input().split()]
    arr = count_sort(arr, no_of_elements, max_number)

    #print("Sorted array:")
    print(arr)

if __name__ == "__main__":
    main()

