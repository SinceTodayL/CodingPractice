#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n;
struct node{
    ll index, value;
    node(ll in, ll val){
        this->index = in;
        this->value = val;
    }
    node(){

    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<ll> nums(n + 1, 0);
    for(ll i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    vector<node> st;
    vector<ll> ans(n + 1, 0);
    ans[1] = 1ll;
    node fir_node = node(1, nums[1]);
    st.push_back(fir_node);
    int top = 0;
    for(ll i = 2; i <= n; ++i){
        if(nums[i] < st[top].value){
            ans[i] = ans[i - 1] ^ i;
            st.push_back(node(i, nums[i]));
            top++;  
        }
        else{
            while(top >= 0 && nums[i] >= st[top].value){
                st.pop_back();
                top--;
            }
            if(top == -1){
                top = 0;
                st.push_back(node(i, nums[i]));
                ans[i] = i;
            }
            else{
                ans[i] = ans[st[top].index] ^ i;
                st.push_back(node(i, nums[i]));
                top++;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}