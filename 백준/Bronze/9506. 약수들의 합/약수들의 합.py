while True:
    n = int(input())
    if n == -1:
        break

    ans = set([1])
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            ans.add(i)
            ans.add(n // i)

    if sum(ans) == n:
        print(f"{n} = {" + ".join(str(i) for i in sorted(ans))}")
    else:
        print(f"{n} is NOT perfect.")
