import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
dq = deque()
st = []
before_command = "0"
for _ in range(N):
    s = input().split()
    if len(s) > 1:
        command, num = s
        if command == "1":
            dq.append(num)
        else:
            dq.appendleft(num)
        st.append(command)
    else:
        if dq:
            before_command = st.pop()
            if before_command == "1":
                dq.pop()
            else:
                dq.popleft()

print("".join(dq) if dq else 0)
