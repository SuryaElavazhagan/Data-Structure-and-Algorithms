from random import randint
"""
    ****************DIVIDE AND CONQUER****************
    * Take last element as pivot
    * Compare the pivot element with all other elements in the sub array
    * If the element is equal to pivot element then decrement
      pivot index and swap the traversing index and pivot index
    * If the element is smaller increase k-index
    * Else dont increment it.
    => Finally k-index will be the starting index of the elements
       bigger than pivot element and all the elements equal to pivot element 
       will be in the last
    => So shift the last portion with k portion
    => Then the pivot and all of its redundant elements will be in final position 
       of the array 
    => Continue this to get Sorted array
"""
def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

def minimum(a, b):
    if a < b:
        return a
    return b

def quick_sort(array, low, high):
    
    if low > high:
        return
    pivot_index = randint(low , high)
    swap(array, high, pivot_index)
    
    i = low
    k = low
    p = high
    while i < p:
        if array[i] < array[p]:
            swap(array, i , k)
            i += 1
            k += 1
        elif array[i] == array[p]:
            p -= 1
            swap(array, i, p)
        else:
            i += 1
    
    m = minimum(p - k, high - p + 1)

    for i in range(0, m):
        swap(array, k + i, high - m + 1 + i)
    quick_sort(array, low, k - 1)
    quick_sort(array, high - p + k + 1, high)

def main():

    #n = int(input("Give n: "))
    n = int(input())
    print("Give n elements: ")
    array = [int(x) for x in input().split()]
    assert(len(array) == n)
    quick_sort(array, 0 , n - 1)
    print("Sorted array: ")
    print(array)

if __name__ == "__main__":
    main()
