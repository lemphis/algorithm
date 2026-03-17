import sys

input = sys.stdin.readline

MOD = 900528

chars = input().strip()
password = input().strip()

m = {c: i for i, c in enumerate(chars)}

count = 0
p = 1
k = len(chars)
if len(password) > 1:
    for i in range(1, len(password)):
        p = (p * k) % MOD
        count = (count + p) % MOD

p = 1
for c in reversed(password):
    count = (count + m[c] * p) % MOD
    p = (p * k) % MOD

print((count + 1) % MOD)
