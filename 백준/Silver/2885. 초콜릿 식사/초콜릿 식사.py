K = int(input())

num = 1
while num < K:
    num <<= 1

count = 0
pieces = 0
temp = num
while K > 0:
    if K >= temp:
        K -= temp
    temp >>= 1
    count += 1

print(num, count - 1)
