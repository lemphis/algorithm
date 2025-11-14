import sys
from itertools import combinations

input = sys.stdin.readline

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

min_diff = float("inf")
for count in range(1, N):
    for comb in combinations(range(N), count):
        a_power = 0
        b_power = 0
        for i in range(count - 1):
            for j in range(i + 1, count):
                a_power += S[comb[i]][comb[j]] + S[comb[j]][comb[i]]

        remaining = list(set(range(N)) - set(comb))
        for i in range(N - count - 1):
            for j in range(i + 1, N - count):
                b_power += S[remaining[i]][remaining[j]] + S[remaining[j]][remaining[i]]

        min_diff = min(min_diff, abs(a_power - b_power))

print(min_diff)
