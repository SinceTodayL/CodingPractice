#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int to_number(int n, string s){
    int value = 1;
    int ans = 0;
    for(int i = n - 1; i >= 0; --i){
        ans += static_cast<int>(s[i] - '0') * value;
        value *= 10;
    }
    return ans;
}

int judge(string& s){
    int hour = to_number(2, s.substr(0, 2));
    int minute = to_number(2, s.substr(3, 2));
    int second = to_number(2, s.substr(6, 2));
    if(hour == 7 || hour == 8  || hour == 18 || hour == 19 || ((hour == 9 || hour == 20) && minute == 0 && second == 0))
        return 0;
    else if(hour == 11 || hour == 12 || (hour == 13 && minute == 0 && second == 0))
        return 1;
    else if(hour == 22 || hour == 23 || hour == 0 || (hour == 1 && minute == 0 && second == 0))
        return 2;
    else 
        return 3;
}

int n, h, m;
unordered_map<string, array<bool, 3>> umap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b, c;
    cin >> n >> h >> m;
    string year = to_string(h);
    string month = to_string(m);
    if(month.size() == 1){
        month = "0" + month;
    }
    for(int i = 1; i <= n; ++i){
        cin >> a >> b >> c;
        if(b.substr(0, 4) != year || b.substr(5, 2) != month){
            continue;
        }
        int temp = judge(c);
        if(temp == 3){
            continue;
        }
        umap[a][temp] = true;
    }
    vector<int> nums(3, 0);
    for(auto p : umap){
        for(int i = 0; i < 3; ++i){
            if(p.second[i]){
                nums[i]++;
            }
        }
    }
    for(int i = 0; i < 3; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}