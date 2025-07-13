import sys

input = sys.stdin.readline

C = int(input())
for _ in range(C):
    S, N, T, L = input().split()
    complexity = S[2:-1]
    max_input_count = int(N)
    time_limit = 100_000_000 * int(L)
    total_time = 1
    if complexity == "N":
        total_time = max_input_count
    elif complexity == "N^2":
        total_time = max_input_count * max_input_count
    elif complexity == "N^3":
        total_time *= max_input_count * max_input_count * max_input_count
    elif complexity == "2^N":
        for i in range(1, max_input_count + 1):
            total_time *= 2
            if total_time > time_limit:
                break
    elif complexity == "N!":
        for i in range(2, max_input_count + 1):
            total_time *= i
            if total_time > time_limit:
                break

    tc_count = int(T)
    total_time *= tc_count

    print("May Pass." if total_time <= time_limit else "TLE!")
