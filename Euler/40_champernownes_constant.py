listed = []

x = 0
while len(listed) < 1000101:
    for digit in list(str(x)):
        listed.append(digit)

    x += 1

product = 1
i = 1
while i < 10000000:
    product*=int(listed[i])
    i *= 10

print(product)