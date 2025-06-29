tc = int(input())
for _ in range(tc):
    n = int(input())
    first_public_key, second_public_key, encrypted_text = [
        input().split() for _ in range(3)
    ]
    second_idx = {word: idx for idx, word in enumerate(second_public_key)}
    key_map = [second_idx[w] for w in first_public_key]

    print(*[encrypted_text[key_map[i]] for i in range(n)])
