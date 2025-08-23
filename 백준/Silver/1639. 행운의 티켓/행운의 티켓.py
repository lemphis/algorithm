S = input().strip()
n = len(S)
ans = 0

for length in range(2, n + 1, 2):  # 짝수 길이만 확인
    for i in range(n - length + 1):
        half = length // 2
        left = S[i : i + half]
        right = S[i + half : i + length]
        if sum(map(int, left)) == sum(map(int, right)):
            ans = max(ans, length)

print(ans)
