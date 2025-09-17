def to_base3(n: int):
    if n == 0:
        return "0"
    digits = []
    while n > 0:
        digits.append(str(n % 3))
        n //= 3

    return "".join(reversed(digits))


N = int(input())

if N == 0:
    print("NO")
else:
    print("NO" if any(digit == "2" for digit in to_base3(N)) else "YES")
