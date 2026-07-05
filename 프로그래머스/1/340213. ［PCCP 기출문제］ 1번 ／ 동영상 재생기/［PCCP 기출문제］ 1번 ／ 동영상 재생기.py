def solution(video_len, pos, op_start, op_end, commands):
    video_len_strs = video_len.split(":")
    video_len_num = int(video_len_strs[0]) * 60 + int(video_len_strs[1])
    pos_strs = pos.split(":")
    time = int(pos_strs[0]) * 60 + int(pos_strs[1])
    op_start_strs = op_start.split(":")
    op_start_num = int(op_start_strs[0]) * 60 + int(op_start_strs[1])
    op_end_strs = op_end.split(":")
    op_end_num = int(op_end_strs[0]) * 60 + int(op_end_strs[1])

    for command in commands:
        if op_start_num <= time <= op_end_num:
                time = op_end_num
        if command == "prev":
            time = max(0, time - 10)
        else:
            time = min(video_len_num, time + 10)
        if op_start_num <= time <= op_end_num:
                time = op_end_num
                
    return f"{(time // 60):02d}:{(time % 60):02d}"