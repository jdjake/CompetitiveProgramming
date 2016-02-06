coin_sum_hash = {}
british_coins = (1,2,5,10,20,50,100,200)

def coin_sum(amount, coins):
    if (amount, coins) in coin_sum_hash.keys():
        return coin_sum_hash[(amount, coins)]

    if (amount == 0): return 1
    elif (not coins): return 0

    current = coins[0]

    possible = [coin_sum(amount - current*x, coins[1:])
            for x in range(0,amount//current + 2)]

    coin_sum_hash[(amount, coins)] = sum(possible)
    return coin_sum_hash[(amount, coins)]

print(coin_sum(200, british_coins))