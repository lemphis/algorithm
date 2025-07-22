import sys

input = sys.stdin.readline

N, M = map(int, input().split())
masks = [0] * N
for _ in range(M):
    cmd = list(map(int, input().split()))
    op = cmd[0]
    i = cmd[1] - 1
    if op == 1:
        x = cmd[2] - 1
        masks[i] |= 1 << x
    elif op == 2:
        x = cmd[2] - 1
        masks[i] &= ~(1 << x)
    elif op == 3:
        masks[i] = (masks[i] << 1) & ((1 << 20) - 1)
    else:
        masks[i] >>= 1

print(len(set(masks)))
