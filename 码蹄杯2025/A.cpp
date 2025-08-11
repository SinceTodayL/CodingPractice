#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> nums[i];
    }
    ll ans = 0;
    int cnt = 0, flag = 1;
    for (int i = 1; i <= n; ++i)
    {
        cnt++;
        if (cnt > 2)
        {
            cnt = 1;
            flag = -flag;
        }
        ans += flag * nums[i];
    }
    cout << ans << endl;
    return 0;
}