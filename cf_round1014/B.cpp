#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int odda = 0, oddb = 0, evena = 0, evenb = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] == '1'){
            if(i & 1){
                odda++;
            }
            else{
                evena++;
            }
        }
        if(b[i - 1] == '0'){
            if(i & 1){
                oddb++;
            }
            else{
                evenb++;
            }
        }
    }
    if((odda <= evenb) && (evena <= oddb)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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