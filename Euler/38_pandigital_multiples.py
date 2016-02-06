import itertools

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

primes = sieve(1000000)
prime_set = set(primes)

max_prime = 0
max_len = 0
for x in range(len(primes)//2):
    prime_sum = 0
    y = x
    while y < len(primes):
        prime_sum += primes[y]
        if max_len < y - x and prime_sum in prime_set:
            max_prime = prime_sum
            max_len = y - x + 1
            print(max_prime, max_len)

        if prime_sum > 1000000:
            break

        y += 1