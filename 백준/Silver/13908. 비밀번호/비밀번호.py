n, m = map(int, input().split())
if m == 0:
    print(10**n)
    exit()

parts = set(input().split())

ans = 0
for i in range(10**n):
    password = set(str(i).rjust(n, "0"))
    if password >= parts:
        ans += 1

print(ans)
