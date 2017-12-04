"""
    ***************SAFE MOVE****************
    => Sort value per unit in decending order
    ***************ALGORITHM****************
    => Insert the largest values[i]/weights[i] to the
        knapsack if it is feasible else fill it as much
        as it can hold
    => Insert the next as per the above rule and continue
"""
def min_val(num_one, num_two):
    """
        Returns minimum of two values
    """
    if num_one <= num_two:
        return num_one
    return num_two

def get_max_index(value_per_unit, no_of_items):
    """
        Gets the maximum index of the item having high value per unit
    """
    max_index = 0
    for i in range(0, no_of_items - 1):
        if value_per_unit[i] >= value_per_unit[max_index]:
            max_index = i
    return max_index

def get_max_value(no_of_items, total_weight, values, weights):
    """
        Actual logic goes here
    """
    value_per_unit = list()
    for i in range(0 , no_of_items):
        value_per_unit.append(values[i] / weights[i])
    #taken_amount = 0
    final_value = 0
    for i in range(0 , no_of_items):
        if total_weight == 0:
            return final_value
    
        max_index = get_max_index(value_per_unit, no_of_items)
        taken_amount = min_val(weights[max_index] , total_weight)
        final_value = final_value + (taken_amount * value_per_unit[max_index])
        weights[max_index] = weights[max_index] - taken_amount
        if weights[max_index] == 0:
            value_per_unit[max_index] = 0
        else:
            value_per_unit[max_index] = values[max_index] - weights[max_index]
        total_weight = total_weight - taken_amount
    return final_value


def start():
    """
        Program starts here
    """
    #no_of_items = int(input("Give total number of items"))
    no_of_items = int(input())
    #total_weight = int(input("Give total capacity of knapsack"))
    total_weight = int(input())

    weights = list()
    values = list()
    #print("Give values and weights")
    temp_value = 0
    temp_weight = 0
    for i in range(0, no_of_items):
        temp_value = int(input())
        temp_weight = int(input())
        weights.append(temp_weight)
        values.append(temp_value)
    #print("Maximum value holded by knapsack:")
    print("%.4f" %get_max_value(no_of_items, total_weight, values, weights))

if __name__ == "__main__":
    start()
