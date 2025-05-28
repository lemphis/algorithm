N, K = map(int, input().split())
A = list(map(int, input().split(",")))

for _ in range(K):
    A = [A[i + 1] - A[i] for i in range(len(A) - 1)]

print(",".join(map(str, A)))
