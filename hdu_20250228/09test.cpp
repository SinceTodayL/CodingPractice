#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_set<ll> s;
ll A;

vector<int> transfer(ll n){
    vector<int> record;
    ll temp = n;
    while(temp != 0){
        record.push_back(temp % A);
        temp /= A;
    }
    return record;
}

ll yu(ll a, ll b){
    vector<int> ta = transfer(a);
    vector<int> tb = transfer(b);
    ll min_size = min(ta.size(), tb.size());
    ll res = 0;
    for(int i = 0; i < min_size; ++i){
        res += min(ta[i], tb[i]) * static_cast<ll>(pow(A, i));
    }
    return res;
}
ll huo(ll a, ll b){
    if(a > b){
        swap(a, b);
    }
    vector<int> ta = transfer(a);
    vector<int> tb = transfer(b);
    ll max_size = max(ta.size(), tb.size());
    ll min_size = min(ta.size(), tb.size());
    ll res = 0;
    for(int i = 0; i < min_size; ++i){
        res += max(ta[i], tb[i]) * static_cast<ll>(pow(A, i));
    }
    for(int i = min_size; i < max_size; ++i){
        res += tb[i] * static_cast<ll>(pow(A, i));
    }
    return res; 
}
ll yihuo(ll a, ll b){
    if(a > b){
        swap(a, b);
    }
    vector<int> ta = transfer(a);
    vector<int> tb = transfer(b);
    ll max_size = max(ta.size(), tb.size());
    ll min_size = min(ta.size(), tb.size());
    ll res = 0;
    for(int i = 0; i < min_size; ++i){
        res += ((tb[i] + ta[i]) % A) * static_cast<ll>(pow(A, i));
    }
    for(int i = min_size; i < max_size; ++i){
        res += tb[i] * static_cast<ll>(pow(A, i));
    }
    return res; 
}

ll N;
vector<ll> nums;

void dfs1(ll index, ll n){
    if(index >= N){
        return;
    }
    ll YU = yu(n, nums[index]);
    ll HUO = huo(n, nums[index]);
    ll YIHUO = yihuo(n, nums[index]);
    s.insert(YU);
    s.insert(HUO);
    s.insert(YIHUO);
    dfs1(index + 1, YU);
    dfs1(index + 1, HUO);
    dfs1(index + 1, YIHUO);
}

void dfs2(ll index, ll n){
    if(index >= N){
        return;
    }
    ll YU = n & nums[index];
    ll HUO = n | nums[index];
    ll YIHUO = n ^ nums[index];
    s.insert(YU);
    s.insert(HUO);
    s.insert(YIHUO);
    dfs2(index + 1, YU);
    dfs2(index + 1, HUO);
    dfs2(index + 1, YIHUO);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    N = 3;
    nums.push_back(2200);
    nums.push_back(14);
    nums.push_back(8);
    // nums.push_back(10);
    // nums.push_back(2);
    A = 5;
    ll x = 6;
    dfs2(0, x);

    ll ans = 0;
    vector<ll> ans_sort;
    for(ll ele : s){
        ans += ele;
        ans_sort.push_back(ele);
    }
    sort(ans_sort.begin(), ans_sort.end());
    for(int i = 0; i < ans_sort.size(); ++i){
        cout << ans_sort[i] << "  ";
    }
    cout << endl;
    cout << ans << endl;
    ll c1_result = 0;
    ll c2_result = 0;
    for(int i = 0; i < nums.size(); ++i){
        c1_result += (x & nums[i]);
        c1_result += (x | nums[i]);
        c1_result += (x ^ nums[i]);
    }
    cout << c1_result << endl;
    
    return 0;
}