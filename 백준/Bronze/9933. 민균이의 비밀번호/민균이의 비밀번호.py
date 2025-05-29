N = int(input())
s = set()
for _ in range(N):
    str = input()
    if str[::-1] in s or str == str[::-1]:
        print(len(str), str[len(str) // 2])
        break
    s.add(str)
