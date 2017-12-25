"""
    ******************DIVIDE AND CONQUER*****************
    * Store the points in the structure like
        -> point
        -> category
      For example: if it is a segment (2, 5)
      store it as (2, 'left') & (5, 'right')
      If it is a point (4)
      store it as (4, 'point')
    * Sort them in non decreasing order:
        Then it will be like
        (2, 'left') (4, 'point') (5, 'right')
        It shows that 4 lies between 2 and 5
    * The important problem to consider lies in sorting
    i.e., (2, 5) (2, 7) (2, 10) => Segments
          (2) (4) (3)           => Points
          then the sorted order should be:
          (2, 'left') (2 , 'left') (2, 'left') (2, 'point')
          (3, 'point') (4, 'point') (5, 'right') (7, 'right')
          (10, 'right')
    => The redundancy should be handled properly.
"""
class coordinates:
    data = 0
    category = 0
    """
        * This index is to store the index of the point.
        * This will be helpful in calculations.
    """
    index = 0

    def __init__(self, data, category, index):
        self.data = data
        self.category = category
        self.index = index

def merge(arr, low, high, mid):
    """
        Actual logic goes here.
    """
    left_index = 0
    right_index = 0
    temp_index = low

    left_size = mid - low + 1
    right_size = high - mid

    left_half = list()
    right_half = list()

    # Inserting left half to left temporary array
    for i in range(0, left_size):
        left_half.append(arr[i + low])
    
    # Inserting right half to right temporary array
    for i in range(0, right_size):
        right_half.append(arr[mid + 1 + i])
    
    # Comparing and storing to temporary array
    while left_index < left_size and right_index < right_size:
        """
            The redundancy is handlede here.
            If the category is same you can push both elements
            from left and right sub array.
            else Check which category is low and push them.
        """
        if left_half[left_index].data == right_half[right_index].data:
            if left_half[left_index].category < right_half[right_index].category:
                arr[temp_index] = left_half[left_index]
                left_index += 1
            elif left_half[left_index].category > right_half[right_index].category:
                arr[temp_index] = right_half[right_index]
                right_index += 1
            else:
                arr[temp_index] = left_half[left_index]
                arr[temp_index] = right_half[right_index]
                left_index += 1
                right_index += 1
        
        elif left_half[left_index].data < right_half[right_index].data:
            arr[temp_index] = left_half[left_index]
            left_index += 1
        else:
            arr[temp_index] = right_half[right_index]
            right_index += 1
        temp_index += 1
    
    # Copying the remaining elements
    # Only one of the loop will be executed.
    while left_index < left_size:
        arr[temp_index] = left_half[left_index]
        temp_index += 1
        left_index += 1
    
    while right_index < right_size:
        arr[temp_index] = right_half[right_index]
        temp_index += 1
        right_index += 1

def merge_sort(arr, low, high):
    """
        Separating is done here.
    """
    if low < high:
        mid = int((low + high) / 2)
        
        # Left half
        merge_sort(arr, low, mid)
        
        # Right half
        merge_sort(arr, mid + 1, high)
        
        # Joining two halves
        merge(arr, low, high, mid)

def get_range(cords, segments, points):
    """
        Since there are two points in segements it takes
        2 * segments + points
    """
    n = ((2 * segments) + points)
    segment_layer = 0
    """
        This layer indicates the number of segments in 
        which the point lies. 
    """
    result = [0 for x in range(0, points)]
    for i in range(0, n):
        if cords[i].category == -1:
            segment_layer += 1
        elif cords[i].category == 1:
            segment_layer -= 1
        elif cords[i].category == 0:
            result[cords[i].index] = segment_layer
    print(result)

def main():
    LEFT = -1 # left side of the segment
    RIGHT = 1 # right side of the segment
    POINT = 0 # point 
    tokens = [int(x) for x in input().split()]
    segments = tokens[0]
    points = tokens[1]
    cords = list()
    for i in range(0, segments):
        tokens = [int(x) for x in input().split()]
        cords.append(coordinates(tokens[0], LEFT, -1))
        cords.append(coordinates(tokens[1], RIGHT, -1))
    tokens = [int(x) for x in input().split()]
    assert(len(tokens) == points)
    for i in range(0, points):
        cords.append(coordinates(tokens[i], POINT, i))
    size = ((2 * segments) + points) - 1
    merge_sort(cords, 0, size)
    get_range(cords, segments, points)

if __name__ == "__main__":
    main()