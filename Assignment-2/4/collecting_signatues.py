"""
    ***************SAFE MOVE****************
    => Sort given segments based on right end
    ***************ALGORITHM****************
    => Check whether right end is to the right of
        next segment left end i.e.,
        > b[i] >= a[i + 1]
    => if not increment the count and add b[i + 1] 
        to the result
"""
class my_coordinates:
    """
        This stores both left and right points of the segment
    """
    point_one = 0
    point_two = 0
    def __init__(self, point_one, point_two):
        self.point_one = point_one
        self.point_two = point_two

def get_min_segment(num, cord):
    """
        Actual logic goes here
    """
    points = list()
    index_one = 1
    index_two = 0
    points.append(cord[index_one].point_two)
    count = 1
    while(index_one < num):
        if points[index_two] >= cord[index_one].point_one:
            index_one += 1
        else:
            points.append(cord[index_one].point_two)
            index_two += 1
            count += 1
            index_one += 1
    print(count , points)

def main():
    """
        Program starts here
    """
    #num = int(input("Give n:"))
    num = int(input())
    cord = list()

    #print("Give the end points of segments:")
    for i in range(0, num):
        temp_cord = [int(x) for x in input().split()]
        cord.append(my_coordinates(temp_cord[0], temp_cord[1]))
    """
        lambda is like inline function in C or C++
        lambda x: x.point_two means 
            => key value will be taken as cord: cord.point_two
    """
    cord.sort(key= lambda x: x.point_two, reverse=False)
    """
    This function is used to print objects
        =>print ([cords.point_two for cords in cord])
    """

    #print("The result is:")
    get_min_segment(num, cord)

if __name__ == "__main__":
    main()

