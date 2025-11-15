import sys

input = sys.stdin.readline

T = int(input())
for i in range(T):
    N = int(input())
    if N == 0:
        print(f"Case #{i+1}: INSOMNIA")
        continue
    check = [False] * 10
    times = 1
    next = N * times
    while True:
        for c in str(next):
            check[int(c)] = True
        if all(check):
            print(f"Case #{i+1}: {next}")
            break
        times += 1
        next = N * times
