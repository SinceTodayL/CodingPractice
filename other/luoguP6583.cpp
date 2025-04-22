#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    下面代码未 AC，有细节问题
*/

ll n, ans = 0;

ll count(ll L, ll R) {
    auto f = [](ll x, ll d) { return x / d; };
    return (f(R,2)-f(L-1,2)) + (f(R,5)-f(L-1,5)) - (f(R,10)-f(L-1,10));
}


vector<ll> f2, f5, f;
ll cal(ll x){
    ll s = 0;
    ll l, r;
    for(l = 1; l <= x; l = r + 1){
        r = n / (n / l);
        ll a = count(l, min(r, x));
        if(r < x)
            s += (r - l + 1 - a) * (n / l);
        else{
            s += (x - l + 1 - a) * (n / l);
            break;
        }
        //cout << l << " " << r << " " << s << endl;
    }
    /*
    for(int i = 1; i < f.size(); ++i){
        if(f[i] <= x){
            s -= (n / f[i]);
        }
    }
    */
    return s;
}

void factor(){
    ll a = 1;
    while(a <= n){
        f2.push_back(a);
        a *= 2;
    }
    a = 1;
    while(a <= n){
        f5.push_back(a);
        a *= 5;
        // cout << a << endl;
    }
    for(ll i : f2){
        for(ll j : f5){
            if(i * j <= n)
                f.push_back(i * j);
            // cout << i << endl;
        }
    }
    sort(f.begin(), f.end());
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    factor();
    for(ll i = 0; i < f.size(); ++i){
        ans += cal(n / f[i]);
        //cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}


/*
Accept code:

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 计算形如2^a*5^b且<=m的数的个数
ll count_2_5(ll m) {
    ll cnt = 0;
    for (ll a = 1; a <= m; a *= 2)
        for (ll b = 1; a*b <= m; b *= 5)
            cnt++;
    return cnt;
}

// 计算[L, R]内与10互质的数的个数（容斥）
ll count_coprime_10(ll L, ll R) {
    if (L > R) return 0;
    auto f = [](ll x, ll d) { return x / d; };
    return (R-L+1) - (f(R,2)-f(L-1,2)) - (f(R,5)-f(L-1,5)) + (f(R,10)-f(L-1,10));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, ans = 0;
    cin >> n;

    // 数论分块枚举d的范围
    for (ll q = 1; q <= n; ) {
        ll current = n / q; // 当前块内n/d的值
        ll next_q = n / current + 1; // 下一个块的起点
        ll k_count = count_2_5(current); // 2^a*5^b的数的个数
        ll d_count = count_coprime_10(q, min(n, next_q-1)); // 与10互质的d的数量
        ans += k_count * current * d_count;
        q = next_q;
    }

    cout << ans << endl;
    return 0;
}

*/