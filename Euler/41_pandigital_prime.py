import itertools
import math

def concat(num_list):
    if len(num_list) == 1: return int(num_list[0])
    return int(num_list[0]) + 10*concat(num_list[1:])

def gcd(x,y):
    if (y == 0): return x
    return gcd(y, x % y)

def check_if_prime(number):
    for i in range(1, int(math.sqrt(number)) + 5):
        if gcd(number, i) != 1 and i != number:
            return False

    print(number)

    return True

pandigitals = []
for i in range(2,10):
    permutations = itertools.permutations(range(1,i))
    number_values = (concat(x) for x in permutations)
    prime_pandigitals = filter(lambda i: check_if_prime(i), number_values)
    pandigitals += list(prime_pandigitals)

print(sorted(pandigitals))
print(max(pandigitals))