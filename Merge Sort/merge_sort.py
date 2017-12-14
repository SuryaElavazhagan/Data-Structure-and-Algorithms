def merge(arr, low, high, mid):
    left_index = 0
    right_index = 0
    temp_index = low

    left_size = mid - low + 1
    right_size = high - mid

    left_half = list()
    right_half = list()

    for i in range(0, left_size):
        left_half.append(arr[i + low])
    
    for i in range(0, right_size):
        right_half.append(arr[mid + 1 + i])
    
    while left_index < left_size and right_index < right_size:
        if left_half[left_index] <= right_half[right_index]:
            arr[temp_index] = left_half[left_index]
            left_index += 1
        else:
            arr[temp_index] = right_half[right_index]
            right_index += 1
        temp_index += 1
    
    while left_index < left_size:
        arr[temp_index] = left_half[left_index]
        temp_index += 1
        left_index += 1
    
    while right_index < right_size:
        arr[temp_index] = right_half[right_index]
        temp_index += 1
        right_index += 1

def merge_sort(arr, low, high):
    if low < high:
        mid = int((low + high) / 2)
        merge_sort(arr, low, mid)
        merge_sort(arr, mid + 1, high)
        merge(arr, low, high, mid)

def main():
    num = int(input())

    arr = [int(x) for x in input().split()]
    merge_sort(arr, 0, num - 1)

    print(arr)

if __name__ == "__main__":
    main()