N = int(input())
for _ in range(N):
    A = list(map(int, input().split()))[1:]
    B = list(map(int, input().split()))[1:]
    for i in range(4, 0, -1):
        a_count = A.count(i)
        b_count = B.count(i)
        if a_count > b_count:
            print("A")
            break
        elif a_count < b_count:
            print("B")
            break

        if i == 1:
            print("D")
