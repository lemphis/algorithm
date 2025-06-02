dp = [0] * 1_001
for i in range(1, 1_001):
    dp[i] = dp[i - 1] + i


def find(target):
    for i in range(1, 1_001):
        if dp[i] > target:
            break
        for j in range(i, 1_001):
            if dp[i] + dp[j] > target:
                break
            for k in range(j, 1_001):
                if dp[i] + dp[j] + dp[k] == target:
                    return True
    return False


T = int(input())
for _ in range(T):
    K = int(input())
    print(1 if find(K) else 0)
