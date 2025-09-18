N = int(input())

l = 1
num = 1
while True:
    is_pass = False
    for c in str(num):
        if l == N:
            is_pass = True
            print(c)
        l += 1
    if is_pass:
        break
    num += 1
