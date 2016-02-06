def sieve(bound):
    is_prime = [1 for y in range(bound)]
    primes = []

    for i in range(2,bound):
        if (is_prime[i]):
            primes.append(i)

            iterator = i
            while (iterator < bound):
                is_prime[iterator] = 0
                iterator += i

    return primes

def gcd(x,y):
    if (y == 0): return x
    return gcd(y, x % y)

primes = sieve(1000000)

prime_factor_hash = {1:set()}

def prime_factors(number):
    if number in prime_factor_hash:
        return prime_factor_hash[number]

    old_number = number

    factors = set()

    i = 0
    while (number != 1):
        while (gcd(primes[i], number) == primes[i]):
            factors |= {primes[i]}
            number = int(number/primes[i])

            prime_factor_hash[old_number] = factors | prime_factor_hash[number]
            return prime_factor_hash[old_number]

        i += 1

    prime_factor_hash[old_number] = factors

    return factors

i = 2
while True:
    if (i % 1000) == 0:
        print(i,prime_factors(i))
    if len(prime_factors(i)) == 4 and len(prime_factors(i+1)) == 4 and len(prime_factors(i+2)) == 4 and len(prime_factors(i+3)) == 4:
        print(i)
        break
    i += 1