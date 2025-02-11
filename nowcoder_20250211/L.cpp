#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a = "CHICKEN";

void solve(){
    int length;
    string s;
    cin >> length >> s;
    if(length % 2 == 0 || length < 7){
        cout << "NO" << endl;
        return;
    }
    int cnt = 0;
    for(int i = 0; i < length; ++i){
        if(a[cnt] != s[i]){
            continue;
        }
        else{
            cnt++;
            if(cnt >= 7){
                break;
            }
        }
    }
    if(cnt < 7){
        cout << "NO" << endl;
        return;
    }
    int temp = (length- 7) / 2;
    vector<int> times(26, 0);
    for(char ch : s){
        times[static_cast<int>(ch - 'A')]++;
    }
    for(int i = 0; i < 26; ++i){
        if(i == static_cast<int>('C' - 'A')){
            if(times[i] - 2 > temp || times[i] < 2){
                cout << "NO" << endl;
                return;
            }
        }
        else if(i == static_cast<int>('H' - 'A') ||
        i == static_cast<int>('I' - 'A') ||
        i == static_cast<int>('K' - 'A') ||
        i == static_cast<int>('E' - 'A') ||
        i == static_cast<int>('N' - 'A')){
            if(times[i] - 1 > temp || times[i] < 1){
                cout << "NO" << endl;
                return;
            }
        }
        else{
            if(times[i] > temp){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
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