import sys

input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
s = int(input())

visited = [False] * n
visited[s - 1] = True
arr = [s - 1]
while arr:
    pos = arr.pop()
    for d in (-A[pos], A[pos]):
        next = pos + d
        if 0 <= next < n and not visited[next]:
            visited[next] = True
            arr.append(next)

print(sum(visited))
