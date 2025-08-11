#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// O(n)
ll cal(int eq, const vector<ll> &nums, ll n, ll x, ll y)
{
    ll cost = 0;

    return cost;
}

void solve()
{
    ll n, x, y, max_ele = 0, min_ele = INT_MAX;
    cin >> n >> x >> y;
    vector<ll> nums(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        max_ele = max(max_ele, nums[i]);
        min_ele = min(min_ele, nums[i]);
    }
    ll left = min_ele, right = max_ele, cost_left, cost_right, cost_mid, ans;
    ll mid = (left + right) >> 1;
    while (left < right)
    {
        mid = (left + right + 1) >> 1;
        cout << mid << endl;
        cost_left = cal(left, nums, n, x, y);
        cost_right = cal(right, nums, n, x, y);
        cost_mid = cal(mid, nums, n, x, y);
        if (cost_left == cost_right)
        {
            ans = cost_mid;
            break;
        }
        else if (cost_right >= cost_mid && cost_mid >= cost_left)
        {
            right = mid - 1;
        }
        else if (cost_right >= cost_left && cost_left >= cost_mid)
        {
            right = mid - 1;
        }
        else if (cost_left >= cost_mid && cost_mid >= cost_right)
        {
            left = mid;
        }
        else if (cost_left >= cost_right && cost_right >= cost_mid)
        {
            left = mid;
        }
        cout << "right and left: " << right << " " << left << endl;
    }
    ans = cal((left + right) >> 1, nums, n, x, y);
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
