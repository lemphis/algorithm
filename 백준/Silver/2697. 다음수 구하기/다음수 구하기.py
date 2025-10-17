import sys

input = sys.stdin.readline


T = int(input())
for _ in range(T):
    A = list(input().strip())

    first_dec_idx = -1
    for i in range(len(A) - 1, 0, -1):
        if A[i] > A[i - 1]:
            first_dec_idx = i - 1
            break

    if first_dec_idx == -1:
        print("BIGGEST")
        continue

    for i in range(len(A) - 1, first_dec_idx, -1):
        if A[i] > A[first_dec_idx]:
            A[i], A[first_dec_idx] = A[first_dec_idx], A[i]
            break

    A[first_dec_idx + 1 :] = A[first_dec_idx + 1 :][::-1]

    print("".join(A))
