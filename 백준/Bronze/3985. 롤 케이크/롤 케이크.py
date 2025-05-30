L = int(input())
N = int(input())

roll_cake = [True] * (L + 1)
expected_num = expected_count = actual_num = actual_count = 0
for i in range(1, N + 1):
    P, K = map(int, input().split())
    if K - P + 1 > expected_count:
        expected_num = i
        expected_count = K - P + 1
    count = 0
    for j in range(P, K + 1):
        if roll_cake[j]:
            count += 1
        roll_cake[j] = False
    if count > actual_count:
        actual_num = i
        actual_count = count

print(expected_num, actual_num, sep="\n")
