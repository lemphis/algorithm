N = int(input())
V = list(map(int, input().split()))
ans = 1
before = 1
for i in range(1, N):
    before = min(before + 1, V[N - 1 - i], i + 1)
    ans += before

print(ans)
