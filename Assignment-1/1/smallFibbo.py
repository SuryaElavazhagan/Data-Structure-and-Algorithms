n = int(input())
fibbo = list()
fibbo.append(0)
fibbo.append(1)

for i in range(2 , n + 1):
    fibbo.append(fibbo[i - 1] + fibbo[i - 2])

print(fibbo[n])