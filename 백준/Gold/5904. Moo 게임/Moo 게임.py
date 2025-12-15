import sys

input = sys.stdin.readline


def find_char(k, idx):
    if k == 0:
        return "moo"[idx]

    mid_idx = length[k - 1]
    right_idx = mid_idx + (1 + k + 2)

    if idx < mid_idx:
        return find_char(k - 1, idx)
    elif idx < right_idx:
        return "m" if idx == mid_idx else "o"
    else:
        return find_char(k - 1, idx - right_idx)


N = int(input())

k = 0
length = [3]
while length[k] < N:
    k += 1
    length.append(length[-1] + (1 + k + 2) + length[-1])

print(find_char(k, N - 1))
