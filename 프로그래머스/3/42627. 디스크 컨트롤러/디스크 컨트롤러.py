import heapq


def solution(jobs):
    jobs.sort()
    heap = []
    idx, time, answer = 0, 0, 0
    n = len(jobs)
    while idx < n or heap:
        while idx < n and jobs[idx][0] <= time:
            heapq.heappush(heap, (jobs[idx][1], jobs[idx][0]))
            idx += 1
        if heap:
            l, s = heapq.heappop(heap)
            answer += time - s + l
            time += l
        else:
            time = jobs[idx][0]

    return answer // n
