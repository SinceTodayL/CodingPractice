#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            cnt++;
            if (cnt > ans)
            {
                ans = cnt;
            }
        }
        else
        {
            cnt--;
        }
    }
    cout << ans << endl;
    return 0;
}