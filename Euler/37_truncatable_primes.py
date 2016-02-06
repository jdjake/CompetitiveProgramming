def concat(digits):
    if len(digits) == 0:
        return 0

    if len(digits) == 1:
        return digits[0]

    return digits[-1] + 10*concat(digits[:-1])

def remove_digit(number):
    digits = [int(y) for y in list(str(number))]
    return concat(digits[:-1])

def remove_digit_right(number):
    digits = [int(y) for y in list(str(number))]
    return concat(digits[1:])

def sieve(bound):
    is_prime = [1 for x in range(bound)]
    primes = []

    for i in range(2,bound):
        if (is_prime[i]):
            primes.append(i)
            iterator = i
            while (iterator < bound):
                is_prime[iterator] = 0
                iterator += i

    return primes

primes_list = sieve(5000000)

def truncatable_prime(number):
    save_number = number

    while (number != 0):
        if number not in primes:
            return False

        number = remove_digit(number)

    number = save_number
    while (number != 0):
        if number not in primes:
            return False

        number = remove_digit_right(number)

    return True

primes = set(primes_list)
truncatable_primes = []
current_prime = 0
while (len(truncatable_primes) < 15):
    prime = primes_list[current_prime]

    if (truncatable_prime(prime)):
        truncatable_primes.append(prime)
        print(prime)

    current_prime += 1

print(sum(truncatable_primes[4:]))