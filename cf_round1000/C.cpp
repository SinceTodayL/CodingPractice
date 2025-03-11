#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int index, value;
};
bool cmp(node& n1, node& n2){
    return n1.value < n2.value;
}

void solve(){
    int n;
    cin >> n;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> out(n + 1);
    int x, y;
    for(int i = 1; i <= n - 1; ++i){
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
        out[x].push_back(y);
        out[y].push_back(x);
    }
    int max1 = 0, max2 = 0;
    vector<int> temp = degree;
    sort(temp.begin() + 1, temp.end());
    max1 = temp[n];
    max2 = temp[n - 1];
    vector<int> max_index;
    for(int i = 1; i <= n; ++i){
        if(max1 == degree[i]){
            max_index.push_back(i);
        }
    }
    vector<node> cost(max_index.size());
    for(int i = 0; i < max_index.size(); ++i){
        cost[i].index = max_index[i];
        cost[i].value = 0;
    }
    for(int i = 0; i < max_index.size(); ++i){
        for(int index : out[max_index[i]]){
            if(degree[index] == max2){
                cost[i].value++;
            }
        }
    }
    sort(cost.begin(), cost.end(), cmp);
    int index1 = cost[0].index;
    int ans = 1;
    ans += (degree[index1] - 1);
    for(int index : out[index1]){
        degree[index]--;
    }
    sort(degree.begin() + 1, degree.end());
    ans += (degree[n - 1] - 1);
    cout << ans << endl;
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