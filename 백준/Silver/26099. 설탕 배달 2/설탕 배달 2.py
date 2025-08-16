N = int(input())

for c in range(N // 5, -1, -1):
    r = N - (c * 5)
    q = r % 3
    if r % 3 == 0:
        print(c + (r // 3))
        exit()

print(-1)
