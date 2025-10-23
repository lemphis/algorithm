word = input()

chars = ["w", "o", "l", "f"]
correct = True
n = len(word)
i = 0
while i < n:
    if word[i] != "w":
        correct = False
        break

    w_count = 1
    for j in range(i + 1, n):
        if word[j] == "w":
            w_count += 1
        else:
            break
    i += w_count

    for c in ["o", "l", "f"]:
        for _ in range(w_count):
            if i < n and word[i] == c:
                i += 1
            else:
                correct = False
                break

    if not correct:
        break

print(1 if correct else 0)
