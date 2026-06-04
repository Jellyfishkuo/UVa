import math, sys

for line in sys.stdin:
    N, M = map(int, line.split())
    num = math.prod(math.comb(*map(int, input().split())) for _ in range(N))
    den = math.prod(math.comb(*map(int, input().split())) for _ in range(M))
    if den == 0 or num % den != 0:
        print(0)
    else:
        ans = num // den
        print(-1 if ans >= 10**100 else ans)
