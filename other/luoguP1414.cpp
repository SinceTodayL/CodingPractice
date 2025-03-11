#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 10010;
const int max_ele = 1000010;
vector<int> nums;
vector<int> factor;
void solve_f(int x){
    for(int i = 1; i * i <= x; ++i){
        if(x % i == 0){
            factor[i]++;
            if(i != x / i){
                factor[x / i]++;
            }
        }
    }
}
map<int, int> mp;

int main(){
    int n;
    cin >> n;
    nums.resize(N, 0);
    factor.resize(max_ele, 0);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        solve_f(nums[i]);
    }

    for(int i = max_ele; i >= 1; --i){
        if(factor[i] != 0){
            if(mp.find(factor[i]) == mp.end()){
                mp[factor[i]] = i;
            }
        }
    }
    vector<int> ans(n + 2, 1);
    for(auto ele : mp){
        ans[ele.first] = ele.second;
    }
    for(int i = n; i >= 1; --i){
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}