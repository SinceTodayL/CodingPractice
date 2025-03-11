#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
struct node{
	ll l, r, w;
}a[100010];
ll mi[100010];
ll mmi[100010];
ll cha = 0;
ll ans = 0;
ll lmax = 0;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>m;
	cha = m;
	for(int i = 0; i < n; ++i){
		cin >> a[i].w >> a[i].l >> a[i].r;
		cha -= a[i].l;
		ans += a[i].l*a[i].w;
	}
	sort(a, a+n, [](node a, node b){return a.w > b.w;});
	for(int i = 0; i < n; ++i){
		mi[i] = a[i].r - a[i].l;
	}	
	for(int i = 0; i < n; ++i){
		mmi[i] = mi[i]*a[i].w;
	}
	for(int i = 1; i < n; ++i){
		mmi[i] += mmi[i-1];
	}
	for(int i = 1; i < n; ++i){
		mi[i] += mi[i-1];
	}
	
    ll index = lower_bound(mi, mi + n, cha) - mi;
    ll tmp = ans;
	ans += cha*a[0].w;
	ll tmpValue = 0;
	if(index != 0){
		tmpValue = mmi[index - 1] + (cha - mi[index - 1])*a[index].w;
	}
	ans = max(tmpValue + tmp, ans);
	for(int i = 0; i < n; ++i){
		if(i >= index){
			int ccha = cha + a[i].l;
			ll iindex = lower_bound(mi, mi + n, ccha) - mi;
			ans = max(ans, tmp + mmi[iindex - 1] + (ccha - mi[iindex - 1])*a[iindex].w - a[i].l*a[i].w);
		}
		else{
			ans = max(tmp + mmi[i] + (cha - mi[i])*a[i].w, ans);
		}
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}

