from functools import reduce
import operator

N = input()
is_pass = False
for i in range(1, len(N)):
    l_str, r_str = N[:i], N[i:]
    l_num = reduce(operator.mul, [int(num) for num in l_str])
    r_num = reduce(operator.mul, [int(num) for num in r_str])
    if l_num == r_num:
        is_pass = True
        break

print("YES" if is_pass else "NO")
