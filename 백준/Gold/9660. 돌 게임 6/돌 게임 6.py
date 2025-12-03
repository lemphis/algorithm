import sys

input = sys.stdin.readline

N = int(input())

print("CY" if N % 7 in [0, 2] else "SK")
