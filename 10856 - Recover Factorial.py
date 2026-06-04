import sys

MAX_M = 2703664
f = [1] * MAX_M
f[0] = 0
f[1] = 0

for i in range(2, MAX_M):
    if f[i] == 1:
        for j in range(2, (MAX_M // i) + 1):
            if i * j < MAX_M:
                f[i * j] = f[i] + f[j]

for i in range(2, MAX_M):
    f[i] += f[i - 1]

cas = 1

for line in sys.stdin:
    n = int(line)
    if n < 0:
        break

    if n == 0:
        print(f"Case {cas}: 0!")
        cas += 1
        continue

    low, high = 0, MAX_M - 1
    ans = -1
    while low <= high:
        mid = (low + high) // 2
        if f[mid] == n:
            ans = mid
            high = mid - 1
        elif f[mid] > n:
            high = mid - 1
        else:
            low = mid + 1

    if ans != -1:
        print(f"Case {cas}: {ans}!")
    else:
        print(f"Case {cas}: Not possible.")

    cas += 1
