triangular = lambda n: int(n*(n+1)//2)
pentagonal = lambda n: int(n*(3*n - 1)//2)
hexagonal = lambda n: n*(2*n - 1)

triangular_set = set()
pentagonal_set = set()
hexagonal_set = set()

k = 1
while k < 1000000:
    print(k)
    triangular_set |= {triangular(k)}
    pentagonal_set |= {pentagonal(k)}
    hexagonal_set  |= {hexagonal(k)}
    k += 1

print(triangular_set & pentagonal_set & hexagonal_set)