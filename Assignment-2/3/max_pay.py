"""
    ***************SAFE MOVE****************
    => Sort given arrays
    ***************ALGORITHM****************
    => Multiply elements from each array
        corresponding to their positions
        and add them to final result
    => Return result
"""
def main():
    """
        Actual logic goes here
    """
    #no_of_ads = int(input("Give no. of ads:"))
    no_of_ads = int(input())

    #print("Give profit per click for i-th ad:")
    profit_per_click = [int(x) for x in input().split()]
    
    #print("Give average clicks per day in i-th slot:")
    avg_click_in_slot = [int(x) for x in input().split()]

    final_value = 0

    profit_per_click.sort()
    avg_click_in_slot.sort()

    for i in range(0, no_of_ads):
        final_value += profit_per_click[i] * avg_click_in_slot[i]
    
    #print("Maximum revenue will be:")
    print(final_value)

if __name__ == "__main__":
    main()
