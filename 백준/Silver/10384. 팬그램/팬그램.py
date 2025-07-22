import sys

input = sys.stdin.readline

n = int(input())
for i in range(n):
    s = input()

    alp = [0] * 26
    for c in s:
        if c.isalpha():
            idx = ord(c.upper()) - ord("A")
            alp[idx] += 1

    min_count = min(alp)
    if min_count == 0:
        print(f"Case {i+1}: Not a pangram")
    elif min_count == 1:
        print(f"Case {i+1}: Pangram!")
    elif min_count == 2:
        print(f"Case {i+1}: Double pangram!!")
    else:
        print(f"Case {i+1}: Triple pangram!!!")
