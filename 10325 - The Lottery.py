import sys
from math import gcd


def lcm(a, b):
    return (a * b) // gcd(a, b)


for line in sys.stdin:
    n, m = map(int, line.split())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(1, 1 << m):
        cnt = 0
        curr_lcm = 1
        for j in range(m):
            if (i >> j) & 1:
                cnt += 1
                curr_lcm = lcm(curr_lcm, a[j])
        if cnt % 2 == 1:
            ans += n // curr_lcm
        else:
            ans -= n // curr_lcm

    print(n - ans)
