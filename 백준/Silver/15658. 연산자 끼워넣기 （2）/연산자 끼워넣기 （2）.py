N = int(input())
A = list(map(int, input().split()))
plus, minus, times, divided = map(int, input().split())
min_result, max_result = 1e9, -1e9


def calculate(idx, now):
    global plus, minus, times, divided, min_result, max_result
    if idx == N:
        if min_result > now:
            min_result = now
        if max_result < now:
            max_result = now
        return

    if plus > 0:
        plus -= 1
        calculate(idx + 1, now + A[idx])
        plus += 1
    if minus > 0:
        minus -= 1
        calculate(idx + 1, now - A[idx])
        minus += 1
    if times > 0:
        times -= 1
        calculate(idx + 1, now * A[idx])
        times += 1
    if divided > 0:
        divided -= 1
        calculate(idx + 1, int(now / A[idx]))
        divided += 1


calculate(1, A[0])

print(int(max_result))
print(int(min_result))
