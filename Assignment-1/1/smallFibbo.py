n = int(input())
fibbo = list()
fibbo.append(0)
fibbo.append(1)
"""
    /*
        * Here last digit of nth fibonacci number is calculated  
        * Each time only the last digit of the fibonacci is calculated
    */
"""
for i in range(2 , n + 1):
    fibbo.append(fibbo[i - 1] + fibbo[i - 2])

print(fibbo[n])