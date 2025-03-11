#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nums[1010][1010];
ll col_sum[1010];
ll row_sum[1010];
struct node{
    ll k = 0;
    ll t = 0;
}axis[2010];

void solve(){
    ll m, n;
    string a;
    cin >> n >> m;
    cin >> a;
    for(int i = 0; i < n; ++i){
        row_sum[i] = 0;
    }
    for(int i = 0; i < m; ++i){
        col_sum[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> nums[i][j];
            col_sum[j] += nums[i][j];
            row_sum[i] += nums[i][j];
        }
    }
    int cur_x = 0, cur_y = 0;
    // first element
    if(a[0] == 'D'){
        axis[0].t = -row_sum[0];
        cur_x++;
    }
    else{
        axis[0].t = -col_sum[0];
        cur_y++;
    }
    ll temp = 0;
    temp += axis[0].t;

    for(int i = 1; i < a.size(); ++i){
        if(a[i] == 'D'){
            if(a[i - 1] == 'D'){
                axis[i].t = -row_sum[cur_x];
            }
            else{
                axis[i].t = -row_sum[cur_x] - temp;
            }
            cur_x++;
        }
        else{
            if(a[i - 1] == 'R'){
                axis[i].t = -col_sum[cur_y];
            }
            else{
                axis[i].t = -col_sum[cur_y] - temp;
            }
            cur_y++;
        }
        if(a[i] != a[i-1]){
            temp = 0;
        }
        temp += axis[i].t;
    }

    if(a[a.size() - 1] == 'R'){
        axis[a.size()].t = -col_sum[m-1];
    }
    else{
        axis[a.size()].t = -row_sum[n-1];
    }
    
    cur_x = 0; cur_y = 0;
    nums[0][0] = axis[0].t;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'R'){
            cur_y++;
            nums[cur_x][cur_y] = axis[i + 1].t;
        }
        else{
            cur_x++;
            nums[cur_x][cur_y] = axis[i + 1].t;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}