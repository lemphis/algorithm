A = int(input())

for n in range(1, A + 1):
    if 31 % (n + 1) == 1:
        print(n)
