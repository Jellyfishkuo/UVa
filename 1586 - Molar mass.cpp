#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        double ans = 0;
        int num = 0;
        char element = '\0';

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            else
            {
                if (element != '\0')
                {
                    if (num == 0)
                        num = 1;

                    if (element == 'C')
                        ans += num * 12.01;
                    else if (element == 'H')
                        ans += num * 1.008;
                    else if (element == 'O')
                        ans += num * 16.00;
                    else if (element == 'N')
                        ans += num * 14.01;
                }

                element = s[i];
                num = 0;
            }
        }

        if (element != '\0')
        {
            if (num == 0)
                num = 1;

            if (element == 'C')
                ans += num * 12.01;
            else if (element == 'H')
                ans += num * 1.008;
            else if (element == 'O')
                ans += num * 16.00;
            else if (element == 'N')
                ans += num * 14.01;
        }

        cout << fixed << setprecision(3) << ans << '\n';
    }

    return 0;
}
