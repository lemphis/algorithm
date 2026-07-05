def solution(bandage, health, attacks):
    t, x, y = bandage
    bandage_time = 0
    idx = 0
    now_health = health
    for time in range(1, attacks[-1][0] + 1):
        if time == attacks[idx][0]:
            _, damage = attacks[idx]
            now_health -= damage
            if now_health <= 0:
                return -1
            bandage_time = 0
            idx += 1
        else:
            now_health = min(health, now_health + x)
            bandage_time += 1
            if bandage_time == t:
                now_health = min(health, now_health + y)
                bandage_time = 0
    
    return now_health