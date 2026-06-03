import sys

ans = [0, 1, 3]
for _ in range(2000):
    ans.append(3 * ans[-1] - ans[-2])

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    print(ans[n])
