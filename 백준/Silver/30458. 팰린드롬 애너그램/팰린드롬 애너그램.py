N = int(input())
S = input().strip()

counts = {}
for c in S:
    if c in counts:
        counts[c] += 1
    else:
        counts[c] = 1

if N & 1:
    counts[S[N // 2]] -= 1

odd_count = 0
for alp in counts:
    if counts[alp] & 1:
        odd_count += 1

print("No" if odd_count > 0 else "Yes")
