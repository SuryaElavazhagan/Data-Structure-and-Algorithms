"""
    ****************DYNAMIC PROGRAMMING******************
    * This program computes discrete knapsack value with repetitions allowed
    * It stores optimized  discrete knapsack value for each weight 
    * from [1.....W] where W is the total_capacity of the given knapsack.
    * It is same as Coin change problem (Dynamic programming).
    * It takes O(n * W) time.
"""

class item:
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value

def knapsack(items, total_weight, total_items):
    values_of_weights = [0 for x in range(0, total_weight + 1)]
    current_value = 0
    for i in range(1, total_weight + 1):
        for j in range(0 , total_items):
            if items[j].weight <= i:
                current_value = values_of_weights[i - items[j].weight] + items[j].value;
            if current_value > values_of_weights[i]:
                values_of_weights[i] = current_value
    
    return values_of_weights[total_weight]

def main():
    total_weight = int(input("Give total capacity of knapsack :"))
    total_items = int(input("Give total number of items :"))
    print("Give weight and value of items :")
    
    items = list()
    for i in range(0, total_items):
        tokens = [int(x) for x in input().split()]
        items.append(item(tokens[0], tokens[1]))
    assert(len(items) == total_items)
    print("The maximum value knapsack can hold is : ",knapsack(items, total_weight, total_items))

if __name__ == "__main__":
    main()