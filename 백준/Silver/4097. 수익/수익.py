import sys

input = sys.stdin.readline

while (N := int(input())) != 0:
    P = [int(input()) for _ in range(N)]
    max_sum = current_sum = P[0]
    for profit in P[1:]:
        current_sum = max(current_sum + profit, profit)
        max_sum = max(max_sum, current_sum)
    print(max_sum)
