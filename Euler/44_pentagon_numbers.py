pentagon = lambda k: int(k*(3*k-1)//2)

min_diff = 1000000
pentagon_list = [pentagon(x) for x in range(1,10000)]
pentagon_set = set(pentagon_list)

for i,pentagon in enumerate(pentagon_list):
    for j,pentagon_2 in enumerate(pentagon_l    ist[i+1:], i+1):
        if pentagon + pentagon_2 in pentagon_set:
            if pentagon_2 - pentagon in pentagon_set:
                print(pentagon,pentagon_2)