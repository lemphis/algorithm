import sys
import re

text = sys.stdin.read()
text = text.split("E-N-D")[0]

words = re.findall(r"[A-Za-z-]+", text)

longest = max(words, key=len)

print(longest.lower())
