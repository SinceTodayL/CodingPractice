#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int N = 100010;
int a[N];
int rightsmall[N];
int leftbig[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    stack<int> st;
    rightsmall[n] = n + 1;
    st.push(n);
    for(int i = n - 1; i >= 1; --i){
        if(a[i] >= a[st.top()]){
            rightsmall[i] = st.top();
            st.push(i);
        }
        else{
            while(!st.empty() && a[i] < a[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                rightsmall[i] = st.top();
            }
            else{
                rightsmall[i] = n + 1;  //当前最小
            }
            st.push(i);
        }
    }
    stack<int> st1;
    leftbig[1] = 0;
    st1.push(1);
    for(int i = 2; i <= n; ++i){
        if(a[i] <= a[st1.top()]){
            leftbig[i] = st1.top();
            st1.push(i);
        }
        else{
            while(!st1.empty() && a[i] > a[st1.top()]){
                st1.pop();
            }
            if(!st1.empty()){
                leftbig[i]  = st1.top();
            }
            else{
                leftbig[i] = 0; // 自己就是最大
            }
            st1.push(i);
        }
    }

    int ptr1 = 1, ptr2 = 1;
    int ans = 0, temp = 1;
    for(ptr1 = 1; ptr1 <= n; ++ptr1){
        ptr2 = max(ptr1 + 1, temp);
        while(ptr2 < rightsmall[ptr1]){
            if(leftbig[ptr2] < ptr1){
                temp = ptr2;
                ans = max(ans, ptr2 - ptr1 + 1);
            }
            ptr2++;
        }
    }
    cout << ans << endl;
    return 0;
}