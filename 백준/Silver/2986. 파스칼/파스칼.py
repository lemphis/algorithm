import sys

input = sys.stdin.readline

is_prime = [True] * 32000
for i in range(2, 32000):
    if is_prime[i]:
        times = 2
        while i * times < 32000:
            is_prime[i * times] = False
            times += 1

N = int(input())

n_prime = True
for i in range(2, 32000):
    if is_prime[i] and N % i == 0:
        n_prime = False
        break

if n_prime:
    print(N - 1)
    exit()

ans = 0
for i in range(2, N):
    if N % i == 0:
        ans = N - (N // i)
        break

print(ans)
