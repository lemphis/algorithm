import sys

input = sys.stdin.readline

N = int(input())
medicines = {a: b for a, b in (tuple(map(int, input().split())) for _ in range(N))}
R = int(input())
for _ in range(R):
    symptoms = list(map(int, input().split()))
    ans = []
    for symptom in symptoms[1:]:
        if symptom in medicines:
            ans.append(medicines[symptom])
        else:
            ans.clear()
            break
    if ans:
        print(*ans, sep=" ")
    else:
        print("YOU DIED")
