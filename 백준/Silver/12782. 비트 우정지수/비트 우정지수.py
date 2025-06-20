T = int(input())
for _ in range(T):
    N, M = input().split()
    n_zero_count = m_zero_count = diff_count = 0
    for i in range(len(N)):
        if N[i] == "0":
            n_zero_count += 1
        if M[i] == "0":
            m_zero_count += 1
        if N[i] != M[i]:
            diff_count += 1
    print(
        abs(n_zero_count - m_zero_count)
        + (diff_count - abs(n_zero_count - m_zero_count)) // 2
    )
