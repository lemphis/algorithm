N = int(input())
if N == 0:
    print(0)
    exit()

digits = []
while N != 0:
    q, r = divmod(N, -2)
    if r < 0:
        r += 2
        q += 1
    N = q
    digits.append(str(r))

print("".join(digits[::-1]))
