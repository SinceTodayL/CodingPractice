#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300010;
int cost[N];
string s;
int n, k;

bool check(int x){
    int cnt = 0;
    bool status = false;
    for(int i = 1; i <= n; ++i){
        if(s[i] == 'B'){
            if(cost[i] > x){
                if(status){
                    continue;
                }
                else{
                    cnt++;
                    status = true;
                }
            }
        }
        else{
            if(cost[i] > x){
                if(status){
                    status = false;
                }
            }
        }
    }
    return cnt <= k;
}

void solve(){
    cin >> n >> k;
    cin >> s;
    s = 'R' + s;
    for(int i = 1; i <= n; ++i){
        cin >> cost[i];
    }
    int right = 1e9, left = 0;
    while(left < right){
        int mid = (left + right) / 2;
        if(check(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left << endl;
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