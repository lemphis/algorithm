def solution(s):
    count = 0
    for c in s:
        if c == "(":
            count += 1
        else:
            if count > 0:
                count -= 1
            else:
                return False

    return count == 0