import sys

input = sys.stdin.readline

N, M = map(int, input().split())
counts = [0] * M
switches = [list(map(int, input().split())) for _ in range(N)]
for switch in switches:
    for item in switch[1:]:
        counts[item - 1] += 1

for switch in switches:
    for item in switch[1:]:
        counts[item - 1] -= 1
    if all(count > 0 for count in counts):
        print(1)
        exit()
    for item in switch[1:]:
        counts[item - 1] += 1

print(0)
