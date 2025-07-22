import sys

input = sys.stdin.readline

N = int(input())
first_round = list(map(abs, map(int, input().split())))
second_round = list(map(abs, map(int, input().split())))

print(sum(first_round) + sum(second_round))
