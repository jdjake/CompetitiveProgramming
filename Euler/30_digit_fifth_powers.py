# What is a bound on sum of fifth powers

# what is the largest n such that n9^5 < 9*sum_{k = 0}^{n-1} 10^n
#                                      = 9(1 - 10^n)/(1 - 10)
#                                      = 10^n - 1
#                                 9^5  < 10^n/n - 1/n

# Which happens for 6 digits, so we need only sum to 999999

print(sum([i for i in range(2, 1000000) if sum([int(x)**5 for x in list(str(i))]) == i]))