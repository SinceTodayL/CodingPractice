#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 1;

ll a[N]; 
ll n, m; 
ll tree[N << 2];
ll tag[N << 2];
ll ls(ll p){
	return p << 1;
}
ll rs(ll p){
	return (p << 1) + 1;
}
void push_up(ll p){
	tree[p] = tree[ls(p)] + tree[rs(p)];
}
void add_tag(ll p, ll pl, ll pr, ll d){
	tag[p] += d;
	tree[p] += (pr - pl + 1) * d;
}
void push_down(ll p, ll pl, ll pr){
	if(tag[p]){
		ll mid = (pr + pl) >> 1;
		add_tag(ls(p), pl, mid, tag[p]);
		add_tag(rs(p), mid + 1, pr, tag[p]);
		tag[p] = 0;
	}
}
void build(ll p, ll pl, ll pr){
	tag[p] = 0;
	if(pl == pr){
		tree[p] = a[pl];
		return;
	}
	ll mid = (pl + pr) >> 1;
	build(ls(p), pl, mid);
	build(rs(p), mid + 1, pr);
	push_up(p);
}
void update(ll L, ll R, ll p, ll pl, ll pr, ll d){
	if(L <= pl && R >= pr){
		add_tag(p, pl, pr, d);
		return;
	}
	push_down(p, pl, pr);
	ll mid = (pl + pr) >> 1;
	if(L <= mid) 
	    update(L, R, ls(p), pl, mid, d);
	if(R > mid)
        update(L, R, rs(p), mid + 1, pr, d);
    push_up(p);
}
ll query(ll L, ll R, ll p, ll pl, ll pr){
	ll ans = 0;
	if(L <= pl && R >= pr){
		return tree[p];
	}
	push_down(p, pl, pr);
	ll mid = (pl + pr) >> 1;
	if(L <= mid)
	    ans += query(L, R, ls(p), pl, mid);
	if(R > mid)
	    ans += query(L, R, rs(p), mid + 1, pr);
	return ans;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	    scanf("%lld", &a[i]);
	build(1, 1, n);
	ll flag, x, y, k; 
	while(m--){
		scanf("%lld", &flag);
		if(flag == 1){
			scanf("%lld %lld %lld", &x, &y, &k);
			update(x, y, 1, 1, n, k);
		}
		else{
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", query(x, y, 1, 1, n));
		}
	}
    return 0;
}

