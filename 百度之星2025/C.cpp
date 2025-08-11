#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

void solve()
{
    ll n, k, input;
    cin >> n >> k;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    unordered_set<int> us1;
    unordered_set<int> us2;
    for (int i = 1; i <= n; ++i)
    {
        cin >> input;
        if (input == 1)
        {
            us1.insert(i);
        }
        else
        {
            us2.insert(i);
        }
    }
    auto isSame = [&](int i, int j)
    {
        return ((us1.find(i) == us1.end()) == (us1.find(j) == us1.end()));
    };
    ll last = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!isSame(i, i - 1))
        {
            if (i == 2)
            {
                dp[i] = 2;
            }
            else
                dp[i] = dp[i - 1] + dp[i - 2] + 1;
            last = 0;
        }

        else
        {
            if (last == 0)
            {
                last = dp[i];
            }
            dp[i] = dp[i - 1] + last;
        }
    }
    cout << dp[n] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
