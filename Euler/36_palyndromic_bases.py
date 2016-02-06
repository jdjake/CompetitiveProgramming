def palindromic(string):
    if (len(string) == 1): return True
    if (len(string) == 0): return True
    if (string[0] != string[len(string) - 1]): return False
    return palindromic(string[1:len(string) - 1])

is_palindromic = lambda x: palindromic(str(x)) and palindromic(bin(x)[2:])
palindromic_numbers = (x for x in range(1,1000000) if is_palindromic(x))
print(sum(palindromic_numbers))