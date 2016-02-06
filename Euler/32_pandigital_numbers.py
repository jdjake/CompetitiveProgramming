import itertools

def concat(num_list):
    if len(num_list) == 1: return int(num_list[0])

    return int(num_list[0]) + 10*concat(num_list[1:])

permutations = itertools.permutations(range(1,10))
permute_product = itertools.product(permutations,range(0,10),range(0,10))
values = ((x[:y], x[y:z], x[z:]) for (x,y,z) in permute_product)
filtered_values = (x for x in values if x[0] and x[1] and x[2])
number_values = (tuple(concat(x) for x in y) for y in filtered_values)
good_values = filter(lambda x: x[0]*x[1] == x[2], number_values)
to_sum = set(x[2] for x in good_values)

print(sum(to_sum))