N = int(input())

for i in range(N, 3, -1):
    str_i = str(i)
    if all(s_i in ["4", "7"] for s_i in str_i):
        print(str_i)
        break
