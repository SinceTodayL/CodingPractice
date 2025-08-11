#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll fp(ll a, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (nums[i] >= m)
        {
            ans += 1;
        }
        else
        {
            cnt = (cnt + fp(nums[i], mod - 2)) % mod;
        }
    }
    ans = (ans + (cnt * m) % mod) % mod;
    cout << ans << endl;
    return 0;
}