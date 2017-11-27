def gcd(a, b):
    if(b == 0):
        return a
    else:
        a = a % b
        return gcd(b , a)

a = int(input())
b = int(input())
#a = int(input("Give a:"))
#b = int(input("Give b:"))
print (int((a * b)/gcd(a, b)))
