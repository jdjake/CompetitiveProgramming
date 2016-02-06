max_solutions = 0
max_p = 0
for p in range(3,1001):
    print(p)
    solutions = [(x,y,p - x - y) for x in range(1,p)
                         for y in range(x,int((p-x)//2))
                         if p - y - x > 0
                         and x**2 + y**2 == (p - x - y)**2]

    if len(solutions) > max_solutions:
        max_solutions = len(solutions)
        max_p = p

print(max_p)