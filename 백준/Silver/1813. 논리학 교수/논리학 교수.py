N = int(input())
nums = list(map(int, input().split()))

count_dict = {n: nums.count(n) for n in set(nums)}
if 0 not in count_dict:
    count_dict[0] = 0

ans = -1
for k, v in sorted(count_dict.items(), reverse=True):
    if k == v:
        ans = k
        break

print(ans)
