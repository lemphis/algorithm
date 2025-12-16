import sys
import re

input = sys.stdin.readline

s = input().strip()

pattern = re.compile(r"(100+1+|01)+")
if pattern.fullmatch(s):
    print("SUBMARINE")
else:
    print("NOISE")
