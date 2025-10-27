def dfs(arr, magic_square, depth, visited):
    global ans

    if depth == 3 and sum(magic_square[0]) != 15:
        return
    if depth == 6 and sum(magic_square[1]) != 15:
        return
    if depth == 7 and sum(row[0] for row in magic_square) != 15:
        return
    if depth == 8 and sum(row[1] for row in magic_square) != 15:
        return
    if depth == 9:
        if (
            sum(row[2] for row in magic_square) != 15
            or sum(magic_square[i][i] for i in range(3)) != 15
            or sum(magic_square[i][2 - i] for i in range(3)) != 15
        ):
            return

        diff = 0
        for r in range(3):
            for c in range(3):
                diff += abs(magic_square[r][c] - arr[r][c])
        if ans > diff:
            ans = diff
        return

    r = depth // 3
    c = depth % 3
    for i in range(1, 10):
        if i not in visited:
            magic_square[r][c] = i
            visited.add(i)
            dfs(arr, magic_square, depth + 1, visited)
            magic_square[r][c] = 0
            visited.remove(i)


A = [list(map(int, input().split())) for _ in range(3)]

magic_square = [[0] * 3 for _ in range(3)]

ans = float("inf")
visited = set()

dfs(A, magic_square, 0, visited)

print(ans)
