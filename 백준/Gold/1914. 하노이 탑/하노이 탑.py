import sys

input = sys.stdin.readline

N = int(input())

print(2**N - 1)
if N > 20:
    exit()


def hanoi(n, start, aux, end):
    if n == 1:
        print(start, end)
        return

    hanoi(n - 1, start, end, aux)
    print(start, end)
    hanoi(n - 1, aux, start, end)


hanoi(N, 1, 2, 3)
