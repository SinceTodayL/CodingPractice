#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200010;
ll nums[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    ll all = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &nums[i]);
        all += nums[i];
    }

    int u, v;
    for (int i = 1; i <= n - 1; ++i)
    {
        scanf("%d%d", &u, &v);
    }

    while (q--)
    {
        ll x;
        cin >> x;
        ll mvalue = all;
        for (int i = 0; i <= 31; ++i)
        {
            if ((x >> i) & 1)
            {
                ll temp = all;
                for (int j = 1; j <= n; ++j)
                {
                    if (!((nums[j] >> i) & 1))
                    {
                        temp += ((nums[j] ^ x) - nums[j]);
                    }
                }
                if (mvalue < temp)
                {
                    mvalue = temp;
                }
            }
        }
        printf("%lld\n", mvalue);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}