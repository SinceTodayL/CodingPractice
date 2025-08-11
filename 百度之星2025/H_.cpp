#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, x, y, repeat = 0, max_ele = 0;
    cin >> n >> x >> y;
    vector<ll> nums(n);
    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        max_ele = max(max_ele, nums[i]);
        mp[nums[i]]++;
    }
    sort(nums.begin(), nums.end());
    for (auto ele : mp)
    {
        repeat = max(repeat, ele.second);
    }
    ll to_zero = max_ele * x;
    for (int i = 0; i < n; ++i)
    {
        to_zero = min(to_zero, nums[i] * x + (n - i - 1) * y);
    }
    ll ans = min((n - repeat) * y, to_zero);
    cout << ans << endl;
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
