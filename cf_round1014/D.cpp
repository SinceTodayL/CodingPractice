#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string Base = "LIT";
    int n; string s;
    cin >> n >> s;
    if(count(s.begin(), s.end(), s[0]) == n) {
        cout << -1 << endl; return;
    }
    vector<int> ans;
    while(1){
        vector<pair<int, char>> cnt;
        for(int i = 0; i < Base.size(); ++i){
            cnt.push_back(make_pair(count(s.begin(), s.end(), Base[i]), Base[i]));
        }
        sort(cnt.begin(), cnt.end());
        if(cnt[0].first == cnt[1].first && cnt[1].first == cnt[2].first){
            break;
        }
        
        auto insert = [&](int i) -> void{
            string base = Base;
            base.erase(find(base.begin(), base.end(), s[i])); base.erase(find(base.begin(), base.end(), s[i + 1]));
            ans.push_back(i);
            s = s.substr(0, i + 1) + base[0] + s.substr(i + 1);
        };

        bool flag = false;
        for(int i = 0; i < s.size() - 1; ++i){
            if(s[i] == s[i + 1]) continue;
            if(s[i] != cnt[0].second && s[i + 1] != cnt[0].second){
                insert(i);
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        for(int i = 0; i < s.size() - 1; ++i){
            if(s[i]== s[i + 1]) continue;
            if(s[i] == cnt[2].second){
                insert(i); insert(i + 1); insert(i); insert(i + 2);break;
            }
            else if(s[i + 1] == cnt[2].second){
                insert(i); insert(i); insert(i + 1); insert(i + 3); break;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] + 1 << endl;
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