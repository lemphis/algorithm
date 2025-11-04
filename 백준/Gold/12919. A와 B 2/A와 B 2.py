from collections import deque

A = input().strip()
B = input().strip()

dq = deque()
dq.append(B)
convert = False
a_len = len(A)
while dq:
    cur = dq.popleft()
    if cur == A:
        convert = True
        break

    if len(cur) > a_len:
        if cur[-1] == "A":
            dq.append(cur[:-1])
        if cur[0] == "B":
            dq.append(cur[::-1][:-1])

print(1 if convert else 0)
