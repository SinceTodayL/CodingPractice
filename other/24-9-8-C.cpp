#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, p;
ll a[100010];

int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= n; ++i)
        if(a[i] > 0)
            p += a[i];
    cout << p;
    return 0;
}

