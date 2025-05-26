word = input()
is_pass = True
for i in range(len(word)):
    if word[i] != word[len(word) - 1 - i]:
        is_pass = False
        break

if is_pass:
    print(1)
else:
    print(0)