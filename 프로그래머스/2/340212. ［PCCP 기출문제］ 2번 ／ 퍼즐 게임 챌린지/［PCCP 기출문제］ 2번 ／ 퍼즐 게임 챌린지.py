def solution(diffs, times, limit):
    lo = 0
    hi = limit
    while lo + 1 < hi:
        mid = (lo + hi) >> 1
        if check(mid, diffs, times, limit):
            hi = mid
        else:
            lo = mid
    
    return hi
    
def check(l, diffs, times, limit):
    total_time = 0
    for i in range(len(diffs)):
        if diffs[i] <= l:
            total_time += times[i]
        else:
            total_time += (diffs[i] - l) * (times[i - 1] + times[i]) + times[i]
            
    return total_time <= limit
        