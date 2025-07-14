import sys

input = sys.stdin.readline

R, C = map(int, input().split())
pixels = [list(map(int, input().split())) for _ in range(R)]
T = int(input())
count = 0
for r in range(R - 2):
    for c in range(C - 2):
        filtered_pixels = [arr[c : c + 3] for arr in pixels[r : r + 3]]
        flat_filtered_pixels = [num for row in filtered_pixels for num in row]
        flat_filtered_pixels.sort()
        if flat_filtered_pixels[4] >= T:
            count += 1

print(count)
