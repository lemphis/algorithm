A, B = map(int, input().split())

L = R = 0
while A > 1 and B > 1:
    if A > B:
        count = A // B
        A -= count * B
        L += count
    else:
        count = B // A
        B -= count * A
        R += count

if A > B:
    L += A - B
else:
    R += B - A

print(L, R)
