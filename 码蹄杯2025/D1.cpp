#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> nums(n + 1);
    ll total = 0;

    // bitcount[j] 表示第 j 位上有多少个 1
    vector<int> bitcount(32, 0);

    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
        total += nums[i];
        for (int j = 0; j < 32; ++j)
        {
            if ((nums[i] >> j) & 1)
                bitcount[j]++;
        }
    }

    // 忽略图结构（无用）
    int u, v;
    for (int i = 1; i < n; ++i)
        cin >> u >> v;

    while (q--)
    {
        ll x;
        cin >> x;
        ll delta = 0;
        for (int j = 0; j < 32; ++j)
        {
            if ((x >> j) & 1)
            {
                int ones = bitcount[j];
                int zeros = n - ones;
                ll contrib = (1LL << j) * (zeros - ones); // 增量
                delta += contrib;
            }
        }
        cout << (total + delta) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
