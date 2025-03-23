#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int a, b, s;
    node(int a, int b): a(a), b(b), s(a+b){}
};
struct cmp {
    bool operator()(const node &x, const node &y) const {
        if(x.s != y.s){
            return x.s < y.s;
        }
        else{
            int bigx = max(x.a, y.a);
            int smallx = min(x.a, y.a);
            int bigy = max(x.b, y.b);
            int smally = min(x.b, y.b);
            if(bigx % 3 == 0 && smallx % 3 == 2 && bigx-smallx == 1 && bigy - smally == 1){
                return x.a > y.a;
            }
            if(x.a != y.a){
                return x.a < y.a;
            }
            else{
                return x.b < y.b;
            }
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> flag(n+1);
    set<node, cmp> st1;
    int k = ceil((sqrt(8.0 * n + 1) - 1) / 2);
    for(int sum = 0; sum < k; ++sum)
        for(int i = 0; i <= sum; ++i)
            st1.insert(node(3*i+1, 3*(sum-i)+1));
    set<node, cmp> st2;
    for(auto &p : st1){
        st2.insert(node(p.a, p.b));
        st2.insert(node(p.a+1, p.b));
        st2.insert(node(p.a, p.b+1));
        st2.insert(node(p.a+2, p.b+2));
    }
    for(int i = 1; i <= n; ++i)
        cin >> flag[i];
    for(int i = 1; i <= n; ++i){
        if(flag[i] == 0){
            auto it = st1.begin();
            st2.erase(node(it->a, it->b));
            cout << it->a << " " << it->b << "\n";
            st1.erase(it);
        }
        else{
            auto it = st2.begin();
            auto it2 = st1.find(node(it->a, it->b));
            if(it2 != st1.end())
                st1.erase(it2);
            if(it->a % 3 == 0)
                cout << it->a - 1 << " " << it->b - 1 << "\n";
            else
                cout << it->a << " " << it->b << "\n";
            st2.erase(it);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
