from sys import maxsize as MAX

def change(money, coins):
    min_no_of_coins = [0] * (money + 1)
    #min_no_of_coins[0] = 0
    no_of_coins = 0
    for i in range(1 , money + 1):
        min_no_of_coins[i] = MAX
        for j in range(0 , 3):
            if(i >= coins[j]):
                num_of_coins = min_no_of_coins[i - coins[j]] + 1
            if(num_of_coins < min_no_of_coins[i]):
                min_no_of_coins[i] = num_of_coins
    return min_no_of_coins[money]

def main():
    money = int(input())
    coins = [1, 3, 4]
    print(change(money, coins))

if __name__ == "__main__":
    main()