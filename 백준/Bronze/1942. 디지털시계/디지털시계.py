import sys

def to_seconds(h, m, s):
    return h * 3600 + m * 60 + s

def parse_time(t):
    h, m, s = map(int, t.split(":"))
    return h, m, s

def clock_number(h, m, s):
    return int(f"{h:02}{m:02}{s:02}")

def count_div3(start, end):
    count = 0
    if start <= end:
        t = start
        while t <= end:
            h = (t // 3600) % 24
            m = (t % 3600) // 60
            s = t % 60
            if clock_number(h, m, s) % 3 == 0:
                count += 1
            t += 1
    else:
        t = start
        while t < 24 * 3600:
            h = (t // 3600) % 24
            m = (t % 3600) // 60
            s = t % 60
            if clock_number(h, m, s) % 3 == 0:
                count += 1
            t += 1
        t = 0
        while t <= end:
            h = (t // 3600) % 24
            m = (t % 3600) // 60
            s = t % 60
            if clock_number(h, m, s) % 3 == 0:
                count += 1
            t += 1
    return count


for line in sys.stdin.read().splitlines():
    start_t, end_t = line.split()
    sh, sm, ss = parse_time(start_t)
    eh, em, es = parse_time(end_t)
    start = to_seconds(sh, sm, ss)
    end = to_seconds(eh, em, es)
    print(count_div3(start, end))