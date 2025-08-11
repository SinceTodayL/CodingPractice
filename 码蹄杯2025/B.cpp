#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<ll> nums(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
    ll ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = (((ans * nums[i]) % mod) + ans) % mod;
    }
    cout << (ans - 1 + mod) % mod << endl;
    return 0;
}