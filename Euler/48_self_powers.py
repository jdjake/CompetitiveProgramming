summed = 0
for i in range(1,1001):
    summed += i**i

print(summed % 100000000000)