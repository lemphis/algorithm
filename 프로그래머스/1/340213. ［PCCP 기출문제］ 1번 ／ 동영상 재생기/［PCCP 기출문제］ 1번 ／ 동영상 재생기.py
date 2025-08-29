def solution(video_len, pos, op_start, op_end, commands):
    now_s = to_second(pos)
    op_start_s = to_second(op_start)
    op_end_s = to_second(op_end)
    end_s = to_second(video_len)
    for command in commands:
        if op_start_s <= now_s < op_end_s:
            now_s = op_end_s
        if command == "prev":
            now_s -= 10
        else:
            now_s += 10
        if now_s < 0:
            now_s = 0
        if now_s > end_s:
            now_s = end_s

    if op_start_s <= now_s < op_end_s:
        now_s = op_end_s
    h = now_s // 60
    m = now_s % 60
    return f"{h:02d}:{m:02d}"


def to_second(time):
    h, m = map(int, time.split(":"))
    return h * 60 + m