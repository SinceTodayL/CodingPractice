#include<bits/stdc++.h>
using namespace std;

/*
int n, k;

void solve(){
    cin >> n >> k;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }

    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int left = n + 1, right = 0, cur_size = 0;
    int ll = n + 1, rr = 0;
    bool f1 = false;
    // pq1.push(nums[1]);
    for(int i = 1; i <= n; ++i){
        if(f1){
            if(nums[i] <= k){
                ll = i - 1;
                break;
            }
        }
        if(pq1.empty() || nums[i] < pq1.top()){
            pq1.push(nums[i]);
        }
        else{
            pq2.push(nums[i]);
        }
        if(cur_size % 2 == 0){
            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        else{
            if(pq1.size() != pq2.size()){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        cur_size++;
        if(pq1.top() <= k){
            left = min(cur_size, left);
            f1 = true;
        }
    }
    pq1 = priority_queue<int>();
    pq2 = priority_queue<int, vector<int>, greater<int>>();
    cur_size = 0;
    bool f2 = false;
    for(int i = n; i >= 1; --i){
        if(f2){
            if(nums[i] <= k){
                rr = i + 1;
                break;
            }
        }
        if(pq1.empty() || nums[i] < pq1.top()){
            pq1.push(nums[i]);
        }
        else{
            pq2.push(nums[i]);
        }
        if(cur_size % 2 == 0){
            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        else{
            if(pq1.size() != pq2.size()){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        cur_size++;
        if(pq1.top() <= k){
            right = max(n + 1 - cur_size, right);
            f2 = true;
        }
    }
    //cout << "lr : " << ll << " " << rr << endl;
    if(right - left > 1){
        cout << "YES" << endl;
        return;
    }

    bool flag1 = false, flag2 = false;
    // left.
    pq1 = priority_queue<int>();
    pq2 = priority_queue<int, vector<int>, greater<int>>();
    cur_size = 0;
    for(int i = ll + 1; i <= n - 1; ++i){
        if(pq1.empty() || nums[i] < pq1.top()){
            pq1.push(nums[i]);
        }
        else{
            pq2.push(nums[i]);
        }
        if(cur_size % 2 == 0){
            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        else{
            if(pq1.size() != pq2.size()){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        cur_size++;
        if(pq1.top() <= k){
            flag1 = true;
            break;
        }
    }
    //cout << "lr : " << left << " " << right << endl;
    // right.
    pq1 = priority_queue<int>();
    pq2 = priority_queue<int, vector<int>, greater<int>>();
    cur_size = 0;
    for(int i = rr - 1; i >= 2; --i){
        if(pq1.empty() || nums[i] < pq1.top()){
            pq1.push(nums[i]);
        }
        else{
            pq2.push(nums[i]);
        }
        if(cur_size % 2 == 0){
            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
        else{
            if(pq1.size() != pq2.size()){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        cur_size++;
        if(pq1.top() <= k){
            flag2 = true;
            break;
        }
    }
    //cout << "lr : " << left << " " << right << endl;
    if(flag1 || flag2){
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
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k, l, r;
    bool f1 = false, f2 = false;
    cin >> n >> k;
    l = n + 1, r = 0;
    vector<int> nums(n + 1);
    vector<int> prefix(n + 1, 0);
    vector<int> suffix(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
        if(nums[i] <= k){
            nums[i] = 1;
        }
        else{
            nums[i] = -1;
        }
        prefix[i] = prefix[i - 1] + nums[i];
        if(prefix[i] >= 0 && !f1){
            l = i;
            f1 = true;
        }
    }
    suffix[n] = prefix[n];
    for(int i = n - 1; i >= 2; --i){
        suffix[i] = max(prefix[i], suffix[i + 1]);
    }
    bool flag1 = false, flag2 = false;
    for(int i = 1; i <= n - 2; ++i){
        if(prefix[i] >= 0 && suffix[i + 1] >= prefix[i]){
            flag1 = true;
            break;
        }
    }
    prefix[n] = nums[n];
    for(int i = n; i >= 2; --i){
        prefix[i - 1] = prefix[i] + nums[i - 1];
       // cout << prefix[i] << '\n';
        if(prefix[i] >= 0 && !f2){
            r = i;
            f2 = true;
        }
    }
    suffix[1] = prefix[1];
    for(int i = 1; i <= n - 1; ++i){
        suffix[i + 1] = max(suffix[i], prefix[i + 1]);
    }
    for(int i = n; i >= 3; --i){
        if(prefix[i] >= 0 && suffix[i - 1] >= prefix[i]){
            flag2 = true;
            break;
        }
    }
//    cout << flag1 << " " << flag2 << '\n';
   // cout << l << " " << r << '\n';
    if(flag1 || flag2 || r - l >= 2){
        cout << "yes" << '\n';
        return;
    }
    else{
        cout << "no" << '\n';
        return;
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