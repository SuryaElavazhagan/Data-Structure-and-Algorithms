"""
    This is Assignment 6
    /*
        * Sum of 'n' fibonacci numbers is => F[n + 2] - 1
        * Explaination in README.md
    */
"""
def load(fib):
    """
    Here fibonacci numbers are stored in fib list
    """
    fib.append(0)
    fib.append(1)
    for i in range(2, 61):
        temp = (fib[i - 1] + fib[i - 2])%10
        if temp == 0:
            temp = 10
        fib.append(temp)

def start():
    """
    Here the program starts
    """
    fib = list()
    num = int(input())
    load(fib)
    print fib[(num +2) % 60] - 1

if __name__ == "__main__":
    start()
