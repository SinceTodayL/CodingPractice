#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<string> s;

bool cmp(string& s1, string& s2){
    int max_size = max(s1.size(), s2.size());
    for(int i = 0; i < max_size; ++i){
        if(s1[i] != s2[i]){
            return s1[i] < s2[i];
        }
    }
    return s1.size() < s2.size();
}

int repeat(string s1, string s2){
    int max_size = max(s1.size(), s2.size());
    int ans = 0;
    for(int i = 0; i < max_size; ++i){
        if(s1[i] == s2[i]){
            ans++;
        }
        else{
            return ans;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    s.resize(n);
    int ans = 0;
    int max_size = 0;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        ans += (s[i].size());
        max_size = max(max_size, static_cast<int>(s[i].size()));
    }

    ans *= 2;
    sort(s.begin(), s.end(), cmp);
    for(int i = 0; i < n - 1; ++i){
        ans -= 2*repeat(s[i], s[i + 1]);
    }
    ans -= max_size;
    cout << ans << endl;
    return 0;
}