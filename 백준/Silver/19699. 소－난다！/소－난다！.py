MAX_SUM = 9000


def dfs(start, total, s, H, depth, M):
    if depth == M:
        if is_prime[total] and total not in s:
            s.add(total)
        return

    for i in range(start, len(H)):
        dfs(i + 1, total + H[i], s, H, depth + 1, M)


N, M = map(int, input().split())
H = list(map(int, input().split()))

is_prime = [True] * (MAX_SUM + 1)
is_prime[0] = is_prime[1] = False
for i in range(2, int((MAX_SUM + 1) ** 0.5)):
    if is_prime[i]:
        for j in range(i + i, (MAX_SUM + 1), i):
            is_prime[j] = False

s = set()
dfs(0, 0, s, H, 0, M)

if s:
    print(*sorted(list(s)), sep=" ")
else:
    print(-1)
