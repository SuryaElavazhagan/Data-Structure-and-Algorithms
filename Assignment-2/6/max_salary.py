"""
    ***************SAFE MOVE****************
    => Join two elements in the array
     > For ex: 21 2 Join them as
     > 212 and 221 and compare them
"""
def get_max(num_one, num_two):
    """
        This function does the comparison process
    """
    temp_a = int(str(num_one) + str(num_two))
    temp_b = int(str(num_two) + str(num_one))
    if temp_a >= temp_b:
        return num_one
    else:
        return num_two

def get_max_salary(n, numbers):
    """
        This function compares all the elements in the list
        and computes result
    """
    temp_n = n
    result = ""
    while temp_n != 0:
        max_num = numbers[0]
        temp_index = 0
        for i in range(0, n):
            max_num = get_max(max_num, numbers[i])
            if(max_num == numbers[i]):
                temp_index = i
        result += str(max_num)
        numbers[temp_index] = 0
        temp_n -= 1
    print(result)

def main():
    """
        Program starts here
    """
    #num = int(input("Give n:"))
    num = int(input())
    #print("Give array of n elements:")
    numbers = [int(x) for x in input().split()]
    assert(len(numbers) == num)
    #print("Maximum salary obtained from the given combination of elements is:")
    get_max_salary(num, numbers)
    #print(get_max(2, 21))

if __name__ == "__main__":
    main()
