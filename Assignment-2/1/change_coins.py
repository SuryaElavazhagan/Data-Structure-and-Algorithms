"""
    ***************SAFE MOVE****************
    => Sort the coins in decending order
    ***************ALGORITHM****************
    => if amount % coins[i] == amount then
        > skip
    => else 
        > total_coins = amount / coins[i]
        > amount = amount % coins[i]
"""
def get_min_coins(amount):
    """
        Store the coins in decending order
    """
    coins = [10, 5, 1]
    #total_coins store the result
    total_coins = 0
    # i is the index value for coins list 
    i = 0
    while amount != 0:
        if amount % coins[i] == amount:
            i = i + 1
            continue
        else:
            total_coins = total_coins + int(amount / coins[i])
            amount = amount % coins[i]
            i = i + 1
    return total_coins

def start():
    """
        This function is the start of the program
    """
    #amount = int(input("Give the amount:"))
    amount = int(input())

    #print("Minimum number of coins required:")
    print(get_min_coins(amount))

if __name__ == "__main__":
    start()
