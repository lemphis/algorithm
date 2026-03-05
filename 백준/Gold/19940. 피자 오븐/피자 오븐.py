import sys

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N = int(input())
    ADDH, ADDT, MINT, ADDO, MINO = 0, 0, 0, 0, 0
    ADDH = N // 60
    N -= ADDH * 60
    if N > 35:
        ADDH += 1
        N -= 60
    if N > 0:
        q, r = N // 10, N % 10
        ADDT += q
        N -= 10 * q
        if r > 5:
            ADDT += 1
            N -= 10
            MINO += 10 - r
            N += 10 - r
        else:
            ADDO += r
            N -= r
    else:
        N = abs(N)
        q, r = N // 10, N % 10
        MINT += q
        N -= 10 * q
        if r > 5:
            MINT += 1
            N -= 10
            ADDO += 10 - r
            N += 10 - r
        else:
            MINO += r
            N -= r

    print(ADDH, ADDT, MINT, ADDO, MINO)
