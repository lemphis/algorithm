def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


R, G = map(int, input().split())

num = gcd(R, G)
divisors = set()
for i in range(1, int(num**0.5) + 1):
    if num % i == 0:
        divisors.add(i)
        divisors.add(num // i)

ans = []
for i in divisors:
    ans.append((i, R // i, G // i))

for tup in ans:
    print(*tup)
