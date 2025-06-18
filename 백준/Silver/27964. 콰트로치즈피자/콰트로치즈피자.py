_ = int(input())
print(
    "yummy"
    if len(set(filter(lambda x: x.endswith("Cheese"), input().split()))) >= 4
    else "sad"
)
