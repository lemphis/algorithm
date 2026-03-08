import sys

input = sys.stdin.readline

n = int(input())

st = []
count = 0

for _ in range(n):
    x, y = map(int, input().split())

    while st and st[-1] > y:
        st.pop()
        count += 1

    if st and st[-1] == y:
        continue

    if y > 0:
        st.append(y)

print(count + len(st))
