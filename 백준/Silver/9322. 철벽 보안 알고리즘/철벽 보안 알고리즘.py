tc = int(input())
for _ in range(tc):
    n = int(input())
    first_public_key, second_public_key, encrypted_text = [
        input().split() for _ in range(3)
    ]
    key_map = {}
    for i in range(n):
        for j in range(n):
            if first_public_key[i] == second_public_key[j]:
                key_map[i] = j
                break
    ans = []
    for i in range(n):
        ans.append(encrypted_text[key_map[i]])

    print(*ans)
