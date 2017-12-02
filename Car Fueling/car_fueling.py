"""
    /*
        * This program has Loop nested within another loop
        * So, it seems to have O(n * n) run-time
        * But, the run time of the program is O(n)
            => currentRefills can be atmost n - 1
            => numRefills can be atmost n
            => So there will be atmost n + 1 operations
                => O(n + 1) => O(n)
    */
"""

"""
/*
    ********************SAFE MOVE**********************
    Moving as far as the fuel is good enought to reach another gas station
*/
"""
def min_refills(n, a, dist_with_full_tank):
    num_refills = 0
    current_refills = 0
    last_refills = 0
    #print("Stops where you need to get refilling:")
    while current_refills < (n - 1):
        last_refills = current_refills
        while ((a[current_refills + 1] - a[last_refills]) <= dist_with_full_tank):
                current_refills = current_refills + 1
                if current_refills == (n - 1):
                    break
        #print(a[last_refills])
        if current_refills == last_refills:
            # This happens when gas station is far away that even full tank of 
            # fuel could not make up
            return "Impossible"
        if current_refills < (n - 1):
            num_refills = num_refills + 1
    return num_refills

def start():
    #print("Give n:")
    n = int(input())
    #print("Give gas station stops in kms:")
    a = [int (x) for x in input().split()]
    assert(len(a) == n)
    #print("Give Mileage per full tank:")
    dist_with_full_tank = int(input())
    #print("Number of refilling required:")
    print(min_refills(n, a, dist_with_full_tank))

if __name__ == "__main__":
    start()