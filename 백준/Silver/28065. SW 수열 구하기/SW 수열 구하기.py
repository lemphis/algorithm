N = int(input())

ans = []
for i in range(N // 2):
    if N & 1:
        ans.append(i + 1)
        ans.append(N - i)
    else:
        ans.append(N - i)
        ans.append(i + 1)

if N & 1:
    ans.append(N // 2 + 1)
print(*ans, sep=" ")
