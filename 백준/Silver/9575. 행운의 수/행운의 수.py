import sys

input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    N = int(input())
    A = list(map(int, input().split()))
    M = int(input())
    B = list(map(int, input().split()))
    K = int(input())
    C = list(map(int, input().split()))

    nums = set()
    for a in A:
        for b in B:
            for c in C:
                total = a + b + c
                if all(c in ["5", "8"] for c in str(total)):
                    nums.add(total)

    print(len(nums))
