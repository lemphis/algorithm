import sys

input = sys.stdin.readline

N = int(input())
prices = [list(map(int, input().split())) for _ in range(N)]


def petals(r, c):
    return [(r, c), (r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)]


visited = [[False] * N for _ in range(N)]
cands = [(r, c) for r in range(1, N - 1) for c in range(1, N - 1)]
min_cost = 1e9


def dfs(idx, depth, cost):
    global min_cost
    if cost >= min_cost:
        return
    if depth == 3:
        min_cost = cost
        return

    for i in range(idx, len(cands)):
        r, c = cands[i]
        p = petals(r, c)
        if any(visited[rr][cc] for rr, cc in p):
            continue
        for rr, cc in p:
            visited[rr][cc] = True
        dfs(i, depth + 1, cost + sum(prices[rr][cc] for rr, cc in p))
        for rr, cc in p:
            visited[rr][cc] = False


dfs(0, 0, 0)

print(min_cost)
