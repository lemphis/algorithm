import sys

input = sys.stdin.readline

N = int(input())
n_nums = list(map(int, input().split()))
M = int(input())
m_nums = list(map(int, input().split()))

MAX = 1_000_000_000
MAX_PRIME_COUNT = int(MAX**0.5) + 1

primes = []
is_prime = [True] * MAX_PRIME_COUNT
for num in range(2, MAX_PRIME_COUNT):
    if is_prime[num]:
        primes.append(num)
        times = 2
        while num * times < MAX_PRIME_COUNT:
            is_prime[num * times] = False
            times += 1

n_prime_count = {k: 0 for k in primes}
m_prime_count = {k: 0 for k in primes}
for num in n_nums:
    temp = num
    for prime in primes:
        while temp % prime == 0:
            n_prime_count[prime] += 1
            temp //= prime
    n_prime_count[temp] = n_prime_count.get(temp, 0) + 1
for num in m_nums:
    temp = num
    for prime in primes:
        while temp % prime == 0:
            m_prime_count[prime] += 1
            temp //= prime
    m_prime_count[temp] = m_prime_count.get(temp, 0) + 1

intersection = {
    k: min(n_prime_count[k], m_prime_count[k])
    for k in n_prime_count.keys() & m_prime_count.keys()
}

ans = 1
overflow = False
for k, v in intersection.items():
    for _ in range(v):
        ans *= k
        if ans >= MAX:
            overflow = True
        ans %= MAX

print(str(ans).zfill(9) if overflow else ans)
