#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    int input;
    multiset<int> numa;
    vector<int> numb; 
    for(int i = 1; i <= n; ++i){
        cin >> input;
        numa.insert(input);
    }
    for(int i = 1; i <= m; ++i){
        cin >> input;
        numb.push_back(input);
    }
    vector<int> div;
    std::function<bool(int)> find = [&](int x){
        if(numa.find(x) != numa.end()){
            div.push_back(x);
            numa.erase(numa.find(x));
            return true;
        }
        if(x <= 1){
            return false;
        }
        bool flag = false;
        if(find((x + 1) / 2)){
            if(find(x / 2)){
                flag = true;
            }
        }
        return flag;
    };
    bool f = true;
    for(int i = 0; i < m; ++i){
        div.clear();
        if(!find(numb[i])){
            for(int ele : div){
                numa.insert(ele);
            }
            f = false;
            break;
        }
    }
    if(f && numa.empty()){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
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