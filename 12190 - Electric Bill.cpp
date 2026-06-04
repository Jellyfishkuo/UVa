#include <bits/stdc++.h>
#define int long long
using namespace std;

int bill(int energy) {
    int consume = 0;
    if (energy <= 100) return energy * 2;
    consume += 100 * 2;
    if (energy <= 10000) return consume + (energy - 100) * 3;
    consume += (10000 - 100) * 3;
    if (energy <= 1000000) return consume + (energy - 10000) * 5;
    consume += (1000000 - 10000) * 5;
    return consume + (energy - 1000000) * 7;
}

main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0) break;
        int l = 0, r = 1000000000; // 電費 10^9 對應的度數不會超過 10^9
        int total = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (bill(m) >= a)
            {
                total = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        l = 0;
        r = total / 2;
        int ans = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int my_bill = bill(m);
            int neighbor_bill = bill(total - m);
            int diff = neighbor_bill - my_bill;
            if (diff == b)
            {
                ans = my_bill;
                break;
            }
            if (diff > b) l = m + 1;
            else r = m - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
