#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int times;
    int index;
}a[1010];
bool cmp(node l, node r){
    if(l.times != r.times){
        return l.times < r.times;
    }
    else{
        return l.index > r.index;
    }
}

void solve(){
    int n;
    cin >> n;
    string input;
    for(int i = 1; i <= n; ++i){
        a[i].times = 0;
        a[i].index = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> input;
        for(int j = i; j < n; ++j){
            if(input[j] == '1'){
                a[j + 1].times++;
            }
            else{
                a[i + 1].times++;
            }
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; ++i){
        cout << a[i].index << " ";
    }
    cout << endl;
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