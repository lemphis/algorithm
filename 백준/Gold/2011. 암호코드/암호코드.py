password = input()

if password.startswith("0"):
    print("0")
    exit()

n = len(password)
dp = [0] * (n + 1)
dp[0] = 1
dp[1] = 1
for i in range(1, n):
    if password[i] == "0" and (password[i - 1] == "0" or password[i - 1] > "2"):
        print("0")
        exit()

    if password[i] != "0":
        dp[i + 1] = dp[i]

    two = int(password[i - 1 : i + 1])
    if 10 <= two <= 26:
        dp[i + 1] += dp[i - 1]

    dp[i + 1] %= 1_000_000

print(dp[-1])
