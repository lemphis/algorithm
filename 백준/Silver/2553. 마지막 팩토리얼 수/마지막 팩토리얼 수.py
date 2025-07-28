N = int(input())

DIV = 10**6
num = 1
for i in range(2, N + 1):
    num *= i
    while num % 10 == 0:
        num //= 10
    num %= DIV

print(num % 10)
