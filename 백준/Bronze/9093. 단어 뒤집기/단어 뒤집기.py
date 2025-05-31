T = int(input())
for _ in range(T):
    print(" ".join(["".join(reversed(w)) for w in input().split()]))
