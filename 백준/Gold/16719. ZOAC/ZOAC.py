import sys

input = sys.stdin.readline


def dfs(s, start, end, visited):
    if start >= end:
        return

    min_pos = start
    min_c = s[start]
    for i in range(start, end):
        if not visited[i] and s[i] < min_c:
            min_c = s[i]
            min_pos = i

    visited[min_pos] = True
    print("".join(s[i] if visited[i] else "" for i in range(len(s))))

    dfs(s, min_pos + 1, end, visited)
    dfs(s, start, min_pos, visited)


s = input().strip()

l = len(s)
min_pos = 0
min_c = s[0]
for i in range(l):
    if s[i] < min_c:
        min_c = s[i]
        min_pos = i

visited = [False] * l
visited[min_pos] = True

print(min_c)
dfs(s, min_pos + 1, l, visited)
dfs(s, 0, min_pos, visited)
