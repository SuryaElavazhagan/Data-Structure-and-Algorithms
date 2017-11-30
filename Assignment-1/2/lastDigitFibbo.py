n = int(input())
previous = 1
current = 0

for i in range(2, n + 1):
    temp_previous = previous
    previous = current
    current = (previous + temp_previous)%10

print (current)
