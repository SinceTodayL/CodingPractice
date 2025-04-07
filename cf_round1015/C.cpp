#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int a, b;
};

void solve(){
    int n;
    cin >> n;
    vector<node> p(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        cin >> p[i].a;
    }
    for(int i = 1; i <= n; ++i){
        cin >> p[i].b;
        if(p[i].a == p[i].b){
            cnt++;
        }
    }
    if((n & 1) && cnt != 1){
        cout << -1 << endl;
        return;
    }
    else if((n % 2 == 0) && cnt != 0){
        cout << -1 << endl;
        return;
    }
    vector<int> pb(n + 1);
    for(int i = 1; i <= n; ++i){
        pb[p[i].b] = i;
    }
    /*
    for(int i = 1; i  <= n; ++i){
        cout << pb[i] << " ";
    }
    cout << endl;
    */
    vector<pair<int, int>> ans;
    for(int i = 1; i <= (n + 1) / 2; ++i){
        if(p[pb[p[i].a]].a != p[i].b){
            /*
            cout << "reason: " << endl;
            cout << i << " " << pb[p[i].a] << " " << p[i].b << endl;
            */
            cout << -1 << endl;
            return;
        }
        else{
            if(p[i].a == p[i].b){
                if(i != (n + 1) / 2){
                    ans.push_back(make_pair(pb[p[i].a], (n + 1) / 2));
                    int t1 = pb[p[i].a];
                    swap(p[t1], p[(n + 1) / 2]);
                    int t2 = p[t1].b, t3 = p[(n + 1) / 2].b;
                    swap(pb[t2], pb[t3]);
                }
            }
            else if(pb[p[i].a] != n + 1 - i){
                ans.push_back(make_pair(pb[p[i].a], n + 1 - i));
                int t1 = pb[p[i].a];
                swap(p[t1], p[n + 1 - i]);
                int t2 = p[t1].b, t3 = p[n + 1 - i].b;
                swap(pb[t2], pb[t3]);
                /*
                cout << "After: " << endl;
                for(int i = 1; i <= n; ++i){
                    cout << pb[i] << " ";
                }
                cout << endl;
                */
            }
        }
    }
    for(int i = 1; i <= (n + 1) / 2; ++i){
        if(p[pb[p[i].a]].a != p[i].b){
            /*
            cout << "reason: " << endl;
            cout << i << " " << pb[p[i].a] << " " << p[i].b << endl;
            */
            cout << -1 << endl;
            return;
        }
        else{
            if(p[i].a == p[i].b){
                if(i != (n + 1) / 2){
                    ans.push_back(make_pair(pb[p[i].a], (n + 1) / 2));
                    int t1 = pb[p[i].a];
                    swap(p[t1], p[(n + 1) / 2]);
                    int t2 = p[t1].b, t3 = p[(n + 1) / 2].b;
                    swap(pb[t2], pb[t3]);
                }
            }
            else if(pb[p[i].a] != n + 1 - i){
                ans.push_back(make_pair(pb[p[i].a], n + 1 - i));
                int t1 = pb[p[i].a];
                swap(p[t1], p[n + 1 - i]);
                int t2 = p[t1].b, t3 = p[n + 1 - i].b;
                swap(pb[t2], pb[t3]);
                /*
                cout << "After: " << endl;
                for(int i = 1; i <= n; ++i){
                    cout << pb[i] << " ";
                }
                cout << endl;
                */
            }
        }
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }

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