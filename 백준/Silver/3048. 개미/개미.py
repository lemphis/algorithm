N1, N2 = map(int, input().split())
ants = list(input()[::-1] + input())
dirs = [True] * N1 + [False] * N2
T = int(input())
for _ in range(T):
    new_ants = [ants[0]] * (N1 + N2)
    new_dirs = [dirs[0]] * (N1 + N2)
    for i in range(1, N1 + N2):
        new_ants[i] = ants[i]
        new_dirs[i] = dirs[i]
        if dirs[i - 1] and not dirs[i]:
            new_dirs[i - 1], new_dirs[i] = new_dirs[i], new_dirs[i - 1]
            new_ants[i - 1], new_ants[i] = new_ants[i], new_ants[i - 1]
    ants = new_ants
    dirs = new_dirs

print("".join(ants))
