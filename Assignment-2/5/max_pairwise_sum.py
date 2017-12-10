"""
    ***************SAFE MOVE****************
    => Always start with 1 and increment till
     k < 2l
      > i.e., For eg., Input : 8
      > Start with => 1     Remaining : 7    > Condition(7 > (2 * 1)) => TRUE   
            > Add 1 to result
      > Increment  => 2     Remaining : 6    > Condition(6 > (2 * 2)) => TRUE
            > Add 2 to result
      > Increment  => 3     Remaining : 5    > Condition(5 > (2 * 3)) => FALSE
            > Add 5 to result
    => Stop
"""
def get_max_pairwise_sum(n):
    pairs = list()
    pairs.append(1)
    temp = 2
    while n != 0:
        if n > (temp * 2):
            pairs.append(temp)
            n -= temp
            temp += 1
        else:
            pairs.append(n)
            break
    print(len(pairs))
    print(pairs)

def main():
    num = int(input())
    
    if num <= 2:
        print("1\n", num)
    else:
        get_max_pairwise_sum(num - 1)
    
if __name__ == "__main__":
    main()
