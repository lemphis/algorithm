N = int(input())
print(len({str(sorted(input())) for _ in range(N)}))
