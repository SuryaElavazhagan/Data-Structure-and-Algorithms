from sys import maxsize

"""
    **************DYNAMIC PROGRAMMING****************
    * In greedy algorithm, The program fails for some test cases like,
    For e.g., coins -> 1 , 8 , 20
              amount -> 24
              Then the greedy algorithm gives => 20 + 1 + 1 + 1 + 1
    * To overcome this, the change for each and every amount is stored 
    * and used whenever needed.
"""

def get_change(money, coins):
    change = [maxsize for x in range(0, money + 1)]
    change[0] = 0
    num_of_coins = 0
    for i in range(1, money + 1):
        for j in range(0, len(coins)):
            if i >= coins[j]:
                num_of_coins = change[i - coins[j]] + 1
            if num_of_coins < change[i]:
                change[i] = num_of_coins
    
    return change[money]

def main():
    num_of_coins = int(input("Give number of coins :"))
    print("Give the coins :")
    coins = [int(x) for x in input().split()]
    assert(len(coins) == num_of_coins)

    money = int(input("Give the amount : "))
    print(get_change(money, coins))

if __name__ == "__main__":
    main()
