N, B = map(int, input().split())

ans = []
while N > 0:
    num = N % B
    ans.append(str(num) if num < 10 else chr(num - 10 + ord("A")))
    N //= B


print("".join(reversed(ans)))
