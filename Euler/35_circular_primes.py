def concat(num_list):
    if (len(num_list) == 1):
        return int(num_list[0])

    return num_list[len(num_list) - 1] + 10*concat(num_list[:len(num_list) - 1])

def sieve(bound):
    is_prime = [1 for i in range(bound)]
    primes = []

    iterator = 2
    while (iterator < bound):
        if (is_prime[iterator]):
            primes.append(iterator)

            counter = iterator
            while (counter < bound):
                is_prime[counter] = 0
                counter += iterator

        iterator += 1

    return set(primes)

def rotate(number):
    number_digits = [int(x) for x in list(str(number))]
    rotated_digits = [number_digits[-1]] + number_digits[:-1]

    return concat(rotated_digits)

prime_set = sieve(1000000)

def is_circular(number):
    for i in range(len(list(str(number))) + 5):
        if number not in prime_set: return False
        number = rotate(number)

    return True

circular_primes = [x for x in prime_set if is_circular(x)]
print(len(circular_primes))