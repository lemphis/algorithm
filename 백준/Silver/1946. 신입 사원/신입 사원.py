import sys

input = sys.stdin.readline

T = int(input())
output = []
for _ in range(T):
    N = int(input())

    ranks = [tuple(map(int, input().split())) for _ in range(N)]

    ranks.sort()

    count = 1
    min_interview = ranks[0][1]
    for _, rank in ranks[1:]:
        if rank < min_interview:
            count += 1
            min_interview = rank

    output.append(count)

print(*output, sep="\n")
