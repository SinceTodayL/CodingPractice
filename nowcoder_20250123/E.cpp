#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
ll nums[N];
ll prefix_nums[N];
ll l, r;
int n, q;


// 线段树
ll tree[N << 2];
ll tag[N << 2];
ll ls(ll p){
    return p << 1;
}
ll rs(ll p){
    return p << 1 | 1;
}
void push_up(ll p){
    tree[p] = min(tree[ls(p)], tree[rs(p)]);
}
void build(ll p, ll pl, ll pr){
    tag[p] = 0;
    if(pl == pr){
        tree[p] = nums[pl];
        return;
    }
    ll mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}



ll query(ll L, ll R, ll p, ll pl, ll pr){
    if(pl >= L && R >= pr){
        return tree[p];
    }
    ll res = LLONG_MAX;
    ll mid = (pl + pr) >> 1;
    if(L <= mid){
        res = min(res, query(L, R, ls(p), pl, mid));
    }
    if(R > mid){
        res = min(res, query(L, R, rs(p), mid + 1, pr));
    }
    return res;
}


void solve(){
    cin >> l >> r;
    int ans = query(l + 1, r, 1, 1, n) - prefix_nums[l - 1];
    cout << max(0, -ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        prefix_nums[i] = prefix_nums[i - 1] + nums[i];
    }
    for(int i = 1; i <= n; ++i){
        nums[i] = prefix_nums[i - 1] - nums[i]; 
    }
    build(1, 1, n);
    while(q--){
        solve();
    }
    /*
    for(int i = 1; i <= n; ++i)
        cout << nums[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i)
        cout << prefix_nums[i] << " ";
    cout << endl;
    */
    return 0; 
}