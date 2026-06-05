#include <bits/stdc++.h>
using namespace std;

vector<int> build(const string& p)
{
    int m = p.length();
    vector<int> nxt(m + 1, 0);
    nxt[0] = -1;
    int i = 0, j = -1;
    while (i < m)
    {
        if (j == -1 || p[i] == p[j])
        {
            i++,j++;
            nxt[i] = j;
        }
        else j = nxt[j];
    }
    return nxt;
}

bool is_p(const string& s)
{
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] != s[r]) return false;
        l++,r--;
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    string r = s;
    reverse(r.begin(), r.end());
    string t1 = s + "#" + r;
    vector<int> nxt1 = build(t1);
    vector<bool> ipp(n + 1, false);
    int cur = nxt1[t1.length()];
    while (cur > 0)
    {
        ipp[cur] = true;
        cur = nxt1[cur];
    }
    string t2 = r + "#" + s;
    vector<int> nxt2 = build(t2);
    vector<bool> isp(n + 1, false);
    cur = nxt2[t2.length()];
    while (cur > 0)
    {
        isp[cur] = true;
        cur = nxt2[cur];
    }
    bool is_a = false;
    for (int i = 1; i < n; i++)
    {
        if (ipp[i] && isp[n - i])
        {
            is_a = true;
            break;
        }
    }
    if(is_a) cout << "alindrome\n";
    else if(is_p(s)) cout << "palindrome\n";
    else cout << "simple\n";
}

int main() 
{
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
