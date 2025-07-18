import sys

input = sys.stdin.readline

p, m = map(int, input().split())
room_idx = 0
rooms = []
for _ in range(p):
    l, n = input().split()
    level = int(l)

    joinable = False
    for room in rooms:
        if len(room) < m and abs(room[0][0] - level) <= 10:
            joinable = True
            room.append((level, n))
            break

    if not joinable:
        rooms.append([(level, n)])

for room in rooms:
    print("Started!" if len(room) == m else "Waiting!")
    room.sort(key=lambda x: x[1])
    for level, name in room:
        print(level, name)
