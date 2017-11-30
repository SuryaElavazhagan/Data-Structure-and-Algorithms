n = int(input())
mod = int(input())
fibbo = list()

fibbo.append(0)
fibbo.append(1)
period = 0
i = 2

while True:
    fibbo.append((fibbo[i - 1] + fibbo[i - 2]) % mod)
    i = i + 1
    period = period + 1
    fibbo.append((fibbo[i - 1] + fibbo[i - 2]) % mod)
    period = period + 1
    if(fibbo[i - 1] == 0 and fibbo[i] == 1):
        break
    i = i + 1

#print (period, '\n')

print (n % period)
