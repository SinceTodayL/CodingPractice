#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    ll k = 0, t = 0;
};

void solve(){
    ll m, n;
    string a;
    cin >> n >> m;
    cin >> a;
    ll sum = 0;
    vector<vector<ll>> nums(n, vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[i][j];
        }
    }
    vector<ll> col_sum(m, 0);
    vector<ll> row_sum(n, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            row_sum[i] += nums[i][j];
        }
    }
    
    cout << 1 << endl; 
    
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            col_sum[j] += nums[i][j];
        }
    }
    vector<node> kt_ans(n + m - 1);
    int cur_x = 0, cur_y = 0;
    if(a[0] == 'D'){
        kt_ans[0].t = -row_sum[0];
        cur_x++;
    }
    else{
        kt_ans[0].t = -col_sum[0];
        cur_y++;
    }

    cout << 2 << endl;

    for(int i = 1; i < a.size(); ++i){
        if(a[i] == a[i-1]){
            if(a[i] == 'D'){
                cur_x++;
                kt_ans[i].t = -row_sum[cur_x];
            }
            else{
                cur_y++;
                kt_ans[i].t = -col_sum[cur_y];
            }
        }
        else{
            if(a[i] == 'D' && a[i-1] == 'R'){
                kt_ans[i].k = 1;
                kt_ans[i].t = -kt_ans[i-1].t - col_sum[cur_y];
                cur_x++;
            }
            else{
                kt_ans[i].k = 1;
                kt_ans[i].t = -kt_ans[i-1].t - row_sum[cur_x];
                cur_y++;
            }
        }
    }
    
    cout << 3 << endl;
    
    if(a[a.size()-1] == 'D'){
         kt_ans[a.size()].t = -row_sum[cur_x];
    }
    else{
        kt_ans[a.size()].t = -col_sum[cur_y];
    }
    ll cnt = 0;
    for(int i = 0; i < n + m - 1; ++i){
        if(kt_ans[i].k == 1){
            cnt++;
        }
    }
    ll all = 0;
    for(int i = 0; i < n; ++i){
        all += row_sum[i];
    }
    for(int i = 0; i < n + m - 1; ++i){
        all += kt_ans[i].t;
    }
    
    cout << 4 << endl;
    cout << cnt + 1 - m << endl;
    sum = all/(cnt + 1 - m);
    cout << "sum: "<< sum << endl;
    nums[0][0] = kt_ans[0].t + sum;
    cout << 4.05 << endl;
    cur_x = 0;
    cur_y = 0;
    for(int i = 0; i <= a.size() - 1; ++i){
        if(a[i] == 'D'){
            cur_x++;
            cout << 4.1 << endl;
            if(kt_ans[i + 1].k == 0)
                nums[cur_x][cur_y] = kt_ans[i + 1].t + sum;
            else{
            	cout << 4.2 << endl;
                nums[cur_x][cur_y] = kt_ans[i + 1].t;
                
                cout << 4.3 << endl;
                
            }
        }
        else{
            cur_y++;
            
            cout << 4.5 << endl; 
            
            if(kt_ans[i + 1].k == 0)
                nums[cur_x][cur_y] = kt_ans[i + 1].t + sum;
            else
                nums[cur_x][cur_y] = kt_ans[i + 1].t;
        }
    }
    
    cout << 5 << endl;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

signed main(){
    int t;
    cin >> t;
    try{
    while(t--){
        solve();
    }
    }
    catch(const std::exception& e){
        cout << e.what() << endl;
    }
    return 0;
}
