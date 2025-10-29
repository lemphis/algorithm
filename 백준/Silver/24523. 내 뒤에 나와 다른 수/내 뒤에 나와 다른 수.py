N = int(input())
A = list(map(int, input().split()))

ans = [-1] * N
for i in range(N - 2, -1, -1):
    if A[i] == A[i + 1]:
        ans[i] = ans[i + 1]
    else:
        ans[i] = i + 1 + 1

print(*ans, sep=" ")
