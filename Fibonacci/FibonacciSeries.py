n = int(input())

a = list()
a.append(0)
a.append(1)

for i in range(2, n):
    a.append(a[i - 1] + a[i -2])

print(a)
