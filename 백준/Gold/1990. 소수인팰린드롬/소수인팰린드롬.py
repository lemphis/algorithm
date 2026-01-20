import sys

input = sys.stdin.readline


def prime(n):
    for prime in primes:
        if n % prime == 0:
            return False
        if prime * prime > n:
            break
    return True


a, b = map(int, (input().split()))
primes = []
is_prime = [True] * (int(b**0.5) + 1)
for i in range(2, int(b**0.5) + 1):
    if is_prime[i]:
        primes.append(i)
        for j in range(i * i, int(b**0.5) + 1, i):
            is_prime[j] = False

ans = []
for i in range(1, 10):
    if i > b:
        break
    if i >= a and prime(i):
        ans.append(i)

if a <= 11 <= b:
    ans.append(11)


n = 10
while True:
    s = str(n)
    p = int(s + s[-2::-1])
    if p > b:
        break
    if p >= a and prime(p):
        ans.append(p)

    n += 1

ans.append(-1)

print(*ans, sep="\n")
