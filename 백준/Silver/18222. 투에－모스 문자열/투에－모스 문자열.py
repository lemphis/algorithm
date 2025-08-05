def dc(k: int, start: int, size: int, type: int):
    if size == 2:
        if type == 0:
            if k == start:
                print(0)
            else:
                print(1)
        if type == 1:
            if k == start:
                print(1)
            else:
                print(0)
        return

    half = size // 2
    if type == 0:
        if start <= k < start + half:
            dc(k, start, half, 0)
        else:
            dc(k, start + half, half, 1)
    else:
        if start <= k < start + half:
            dc(k, start, half, 1)
        else:
            dc(k, start + half, half, 0)


k = int(input())

dc(k - 1, 0, 1 << k.bit_length(), 0)
