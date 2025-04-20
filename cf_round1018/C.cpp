#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve(){
    int n;
    cin >> n;

    vector<vector<ll> > nums(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> nums[i][j];
        }
    }

    vector<vector<ll> > row(n + 1, vector<ll>(n + 1, 0));
    vector<vector<ll> > col(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j < n; ++j){
            row[i][j] = nums[i][j] - nums[i][j + 1];
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            col[i][j] = nums[i][j] - nums[i + 1][j];
        }
    }

    vector<ll> score_row(n + 1), score_col(n + 1);
    for(int i = 1; i <= n; ++i) 
        cin >> score_row[i];
    for(int j = 1; j <= n; ++j) 
        cin >> score_col[j];

    vector<bool> same_row(n + 1, true), rise_row(n + 1, true), fall_row(n + 1, true);
    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            ll d = col[i][j];
            if(d == 0) 
                same_row[i] = false;
            else if(d == 1) 
                rise_row[i] = false;
            else if(d == -1) 
                fall_row[i] = false;
        }
    }

    vector<bool> same_col(n + 1, true), rise_col(n + 1, true), fall_col(n + 1, true);
    for(int j = 1; j < n; ++j){
        for(int i = 1; i <= n; ++i){
            ll d = row[i][j];
            if(d == 0) 
                same_col[j] = false;
            else if(d == 1) 
                rise_col[j] = false;
            else if(d == -1) 
                fall_col[j] = false;
        }
    }

    vector<vector<ll> > dpR(n + 1, vector<ll>(2, INF));
    dpR[1][0] = 0;
    dpR[1][1] = score_row[1];
    for(int i = 1; i < n; ++i){
        for(int s = 0; s < 2; ++s){
            if(dpR[i][s] == INF) continue;
            for(int t = 0; t < 2; ++t){
                ll delta = t - s;
                bool ok = false;
                if(delta == 0) 
                    ok = same_row[i];
                else if(delta == 1) 
                    ok = rise_row[i];
                else if(delta == -1) 
                    ok = fall_row[i];
                if(!ok) 
                    continue;
                ll cost = (t ? score_row[i + 1] : 0LL);
                if(dpR[i + 1][t] > dpR[i][s] + cost){
                    dpR[i + 1][t] = dpR[i][s] + cost;
                }
            }
        }
    }
    ll bestR = min(dpR[n][0], dpR[n][1]);

    vector<vector<ll> > dpC(n + 1, vector<ll>(2, INF));
    dpC[1][0] = 0;
    dpC[1][1] = score_col[1];
    for(int j = 1; j < n; ++j){
        for(int s = 0; s < 2; ++s){
            if(dpC[j][s] == INF) continue;
            for(int t = 0; t < 2; ++t){
                ll delta = t - s;
                bool ok = false;
                if(delta == 0) 
                    ok = same_col[j];
                else if(delta == 1) 
                    ok = rise_col[j];
                else if(delta == -1) 
                    ok = fall_col[j];
                if(!ok) 
                    continue;
                ll cost = (t ? score_col[j + 1] : 0LL);
                if(dpC[j + 1][t] > dpC[j][s] + cost){
                    dpC[j + 1][t] = dpC[j][s] + cost;
                }
            }
        }
    }
    ll bestC = min(dpC[n][0], dpC[n][1]);

    ll ans = (bestR >= INF || bestC >= INF) ? -1 : bestR + bestC;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
