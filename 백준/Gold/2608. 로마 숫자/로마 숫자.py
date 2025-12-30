import sys

input = sys.stdin.readline

roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
convert_target = {
    "IV": "IIII",
    "IX": "VIIII",
    "XL": "XXXX",
    "XC": "LXXXX",
    "CD": "CCCC",
    "CM": "DCCCC",
}

a = input().strip()
b = input().strip()

for k, v in list(convert_target.items())[::-1]:
    if k in a:
        a = a.replace(k, v)
    if k in b:
        b = b.replace(k, v)

a_num = sum(roman[c] for c in a)
b_num = sum(roman[c] for c in b)

sum_num = a_num + b_num

print(sum_num)

sum_roman = []
for d in sorted(([item[::-1] for item in roman.items()]), reverse=True):
    q = sum_num // d[0]
    if q == 0:
        continue
    sum_roman.append(d[1] * q)
    sum_num %= q * d[0]

new_roman = "".join(sum_roman)
for v, k in [item[::-1] for item in list(convert_target.items())[::-1]]:
    if v in new_roman:
        new_roman = new_roman.replace(v, k)

print(new_roman)
