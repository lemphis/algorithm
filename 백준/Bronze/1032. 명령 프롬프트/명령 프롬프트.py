N = int(input())
file_names = [input() for _ in range(N)]
pattern = ""
for i in range(len(file_names[0])):
    c = file_names[0][i]
    is_same = True
    for j in range(1, N):
        if file_names[j][i] != c:
            is_same = False
            break
    pattern += c if is_same else "?"

print(pattern)
