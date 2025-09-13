import sys

input = sys.stdin.readline

N, M, K = map(int, input().split())
seats = [list(input().strip()) for _ in range(N)]

ans = 0
for row in seats:
    seat_count = sum(1 if seat == "0" else 0 for seat in row[:K])
    if seat_count == K:
        ans += 1
    for i in range(M - K):
        seat_count -= 1 if row[i] == "0" else 0
        seat_count += 1 if row[K + i] == "0" else 0
        if seat_count == K:
            ans += 1

print(ans)
