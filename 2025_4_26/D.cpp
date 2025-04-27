#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int v, w;
};
bool cmp1(node& a, node& b){
    return (a.v + a.w) > (b.v + b.w);
}
bool cmp2(node& a, node& b){
    return a.w > b.w;
}

vector<node> st;
int n;

bool check(int x){
    vector<node> sma, big, equ;
    for(int i = 0; i < n; ++i){
        if(st[i].v < x){
            sma.push_back(st[i]);
        }
        else if(st[i].v == x){
            equ.push_back(st[i]);
        }
        else{
            big.push_back(st[i]);
        }
    }
    if(sma.empty()){
        // cout << "jump: " << x << endl;
        return true;
    }
    if(sma.size() > big.size() + equ.size()){
        return false;
    }
    for(int i = 0; i < equ.size(); ++i){
        big.push_back(equ[i]);
    }
    sort(big.begin(), big.end(), cmp1);
    sort(sma.begin(), sma.end(), cmp2);
    for(int i = 0; i < sma.size(); ++i){
        // cout << x + sma[i].w << " " << big[i].v + big[i].w << endl;
        if(x + sma[i].w > big[i].v + big[i].w){
            return false;
        }
    }
    return true;
}

void solve(){
    cin >> n;
    st.clear();
    st.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> st[i].v >> st[i].w;
    }
    int left = 1, right = 1e9, mid;
    while(left < right){
        mid = (left + right) / 2;
        if(check(mid)){
            left = mid + 1;
        }
        else{
            right = mid;
        }
        // cout << "l, r: " << left << " " << right << endl;
    }
    cout << right - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}