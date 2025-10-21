import sys
import bisect

input = sys.stdin.readline

N = int(input())
meetings = [tuple(map(int, input().split())) for _ in range(N)]

meetings.sort(key=lambda x: x[1])

last_time = meetings[-1][1]
dp = [0] * (N + 1)
ends = [meeting[1] for meeting in meetings]
for i in range(1, N + 1):
    start, end, people = meetings[i - 1]
    j = bisect.bisect_right(ends, start)
    dp[i] = max(dp[i - 1], dp[j] + people)

print(dp[-1])
