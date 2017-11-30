def load(fib, n, m):
    """
        Actual logic goes here
    """
    fib.append(0)
    fib.append(1)
    for i in range(2, 61):
        temp = (fib[i - 1] + fib[i - 2]) % 10
        if temp == 0:
            temp = 10
        fib.append(temp)
    
    temp1 = fib[(m + 2) % 60]
    temp2 = fib[(n + 2) % 60]
    if temp2 < temp1:
        temp2 = temp2 + 10
    
    return temp2 - temp1

def start():
    """
        This method is the start of the program
    """
    m = int(input())
    n = int(input())
    fib = list()
    print(load(fib, n, m-1))

if __name__ == "__main__":
    start()
