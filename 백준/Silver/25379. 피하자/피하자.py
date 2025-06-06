N = int(input())
A = list(map(int, input().split()))
even_idx = [i for i in range(N) if A[i] & 1 == 0]
front = [x - y for x, y in zip(even_idx, [i for i in range(len(even_idx))])]
back = [y - x for x, y in zip(even_idx, [i for i in range(N - len(even_idx), N)])]
print(min(sum(front), sum(back)))
