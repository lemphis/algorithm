import sys
import re

input = sys.stdin.readline


def dfs(ans, result, depth, N):
    if depth == N:
        tokens = re.findall(r"\d+|[+\-]", result)
        total = int(tokens[0])
        for i in range(1, len(tokens), 2):
            if tokens[i] == "-":
                total -= int(tokens[i + 1])
            else:
                total += int(tokens[i + 1])

        if total == 0:
            ans.append(result)

        return

    dfs(ans, result + str(depth + 1), depth + 1, N)
    dfs(ans, result + "+" + str(depth + 1), depth + 1, N)
    dfs(ans, result + "-" + str(depth + 1), depth + 1, N)


tc = int(input())
for _ in range(tc):
    N = int(input())
    ans = []
    dfs(ans, "1", 1, N)

    new_ans = []
    for s in ans:
        new_s = ""
        for i in range(len(s) - 1):
            new_s += s[i]
            if s[i].isdigit() and s[i + 1].isdigit():
                new_s += " "
        new_ans.append(new_s + s[-1])

    for s in new_ans:
        print(s)

    print()
