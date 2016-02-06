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

    return set(primes)

primes = sieve(1000000)

def possible(i):
    for prime in primes:
        x = 1

        while (prime + 2*x*x <= i):
            if prime + 2*x*x == i:
                return True

            x += 1

    return False

i = 3
while True:
    if i not in primes and not possible(i):
        print(i)

    i += 2