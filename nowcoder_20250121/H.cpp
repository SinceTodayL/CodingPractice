#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
struct node{
    int l, r, length, num;
};

class cmp{
public:
    bool operator()(node left, node right){
        return left.r >= right.r;
    }
};

bool cmp_sort(node left, node right){
    return left.l <= right.l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<node> a(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i].l >> a[i].r;
        a[i].length = a[i].r - a[i].l + 1;
        a[i].num = i;
    }

    sort(a.begin() + 1, a.end(), cmp_sort);
    priority_queue<node, vector<node>, cmp> pq ;
    vector<int> ans(n + 1);
    int index = 1;
    for(int i = 1; i <= n; ++i){
        while(a[index].l <= i && index <= n){
            pq.push(a[index]);
            index++;
        }
        if(pq.top().r >= i){
            ans[pq.top().num] = i;
            pq.pop();
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(!pq.empty()){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}