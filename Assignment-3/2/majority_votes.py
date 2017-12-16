#from random import randint

"""
    ***************DIVIDE AND CONQUER*****************
    * Divide the array into two halves.
    * Get the majority element from both the halves.
    * And compare both the majority elements and get the result.

    Note:
        This can also be done using Hash table with O(n) time complexity
        but for now it runs O(nlogn) => Divide and conquer method.
"""

def get_majority_element(array, left_majority_element, right_majority_element, low, high):
    """
        This returns the majority element among
        both left and right array.
    """
    no_vote = -1
    left_count = 0
    right_count = 0

    for i in range(0, high + 1):
        # Counting left and right votes
        if array[i] == left_majority_element:
            left_count += 1
        if array[i] == right_majority_element:
            right_count += 1
    
    """
        On dividing array into half majority level changes
        i.e., for n = 10, majority votes will be >5
        if it is split to two halves 5 & 5

        for n = 5 => majority votes will be >2
    """
    majority_limit = int((high - low + 1) / 2)

    if left_count > majority_limit:
        return left_majority_element
    elif right_count > majority_limit:
        return right_majority_element
    else:
        """
            If both left and right elements are not majority element
            Then return negative means no vote.
        """
        return no_vote
        
def get_majority(array, low, high):
    """
        This divides the array and send to get_majority element
        array.
    """
    # Base case => Divided array is at last level
    if low == high:
        return array[low]
    
    # Compute mid index
    mid = int((low + high) / 2)

    # Left half
    left_majority_element = get_majority(array, low, mid)
    
    # Right half
    right_majority_element = get_majority(array, mid + 1, high) 
    
    # Returning the majority element if present, else -1.
    return get_majority_element(array, left_majority_element, right_majority_element, low, high)

"""
def naive_algorithm(array, n):

    # This implements naive algorithm.
    if n <= 2:
        return 0

    current_element = 0
    count = 0

    for i in range(0, n):
        current_element = array[i]
        count = 0
        for j in range(0, n):
            if current_element == array[j]:
                count += 1
        if count > int(n / 2):
            return 1    
    
    return 0
""""
def divide_and_conquer(array, n):

    if n <= 2:
        return 0

    if get_majority(array, 0, n - 1) == -1:
        return 0
    else:
        return 1

"""
def stress_testing():
    # This implements stress testing.
    while True:
        n = randint(1, 100)
        print(n)

        array = [randint(1, 100000) for x in range(n)]
        print(array)
        
        if naive_algorithm(array, n) == divide_and_conquer(array, n):
            print("Success")
        else:
            print("Failed.")
            break
"""
def main():
    """
        Program starts here.
    """
    #stress_testing()
    
    #n = int(input("Give n:"))
    n = int(input())

    #print("Give n elements:")
    array = [int(x) for x in input().split()]
    
    #print("Majority element found (1 / 0):")
    print(divide_and_conquer(array, n))
    
if __name__ == "__main__":
    main()
        