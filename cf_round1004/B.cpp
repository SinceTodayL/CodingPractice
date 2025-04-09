#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int temp = 0;
    for (int i = 0; i < n; i += 2) {
        if (max(temp, a[i]) != max(temp, a[i + 1])) {
            cout << "No" << endl;
            return;
        }
        temp = max(temp, a[i]) + 1;
    }
    cout << "Yes" << endl;
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