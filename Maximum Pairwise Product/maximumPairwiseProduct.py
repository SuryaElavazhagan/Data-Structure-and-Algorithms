import random
"""
def stressTesting():
    while (True):
        n = random.randint(2, 10)
        print(n , '\n')
        numbers = list()
        for i in range(0 , n):
            numbers.append(random.randint(0, 100000))
        for i in range(0 , n):
            print(numbers[i] , ' ')
        resultSlow = maximumPairwise(numbers)
        resultFast = maximumPairwiseFast(numbers)
        if (resultSlow == resultFast):
            print ("Success")
        else:
            print ("Failed : " , "Slow : " , resultSlow , " Fast : " , resultSlow)
            break

def maximumPairwise(a):
    n = len(a)
    result = 0
    for i in range(0, n):
        for j in range(i+1, n):
            if a[i]*a[j] > result:
                result = a[i]*a[j]
    return result
"""
def maximumPairwiseFast(a):
    n = len(a)
    maxIndexOne = -1
    maxIndexTwo = -1
    for i in range(0 , n):
        if(maxIndexOne == -1  or a[i] > a[maxIndexOne]):
            maxIndexOne = i

    for i in range(0 , n):
        if((maxIndexTwo == -1 or a[i] > a[maxIndexTwo]) and i != maxIndexOne):
            maxIndexTwo = i
    return a[maxIndexOne] * a[maxIndexTwo]

n = int(input())
"""
    input().split() returns a char/string based on split() function
    This split function can be overloaded with Delimiter like ' ' or 'a'
    The loop:
        for x in input.split() => since input.split returns a char / string let the value be 'a'
        for x in a  => each value is type casted to int by int (x)
        and all the values will be stored in a[]         
"""
a = [int(x) for x in input().split()]
"""
    assert is a function used to check a condition, if the condition fails it throws 
    an exception. For example here assert checks whether 'n' number of elements are
    loaded into array 'a' if not it throws something like,
    
    Traceback (most recent call last):
    File "maximumPairwiseProduct.py", line 38, in <module>
        assert(len(a) == n)
        AssertionError
"""
assert(len(a) == n)
print(maximumPairwiseFast(a))

#stressTesting()
