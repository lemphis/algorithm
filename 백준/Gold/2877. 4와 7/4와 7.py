import sys

input = sys.stdin.readline

K = int(input())

exp = 1
while 2**exp < K:
    K -= 2**exp
    exp += 1
K -= 1

num_str = "4" * exp
idx = exp - 1
while K > 0:
    if K & 1:
        num_str = num_str[:idx] + "7" + num_str[idx + 1 :]
    K >>= 1
    idx -= 1

print(num_str)
