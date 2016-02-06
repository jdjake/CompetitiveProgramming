from itertools import count

def factorial(n):
    if (n == 0): return 1
    else: return n*factorial(n-1)

def fact_digits(n):
    return sum([factorial(int(x)) for x in list(str(n))])

numbers = (x for x in range(10,1000000) if fact_digits(x) == x)
for num in numbers:
    print(num)