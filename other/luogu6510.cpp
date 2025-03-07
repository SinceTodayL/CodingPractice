#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int n;
const int N = 100010;
int a[N];
int rightsmall[N];
int leftbig[N];
stack<int> st;

signed main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        leftbig[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    while(st.size()){
        st.pop();
    }
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.top()] > a[i]) {
           
            st.pop();
        }
        rightsmall[i] = st.empty() ? (n + 1) : st.top();
        st.push(i);
    }

    int ptr1, ptr2;
    int ans = 0;
    for(ptr1 = 1; max(ptr1, ptr1 + ans - 1) <= n; ++ptr1) {
        for(ptr2 = rightsmall[ptr1] - 1 ; ptr2 > ptr1; --ptr2){
            /*
            if(ptr2 - ptr1 + 1 <= ans){
                break;
            }
            */
            /*
            if(a[ptr2] <= a[ptr1]){
                continue;
            }
            */
            if(leftbig[ptr2] < ptr1){
                ans = max(ans, ptr2 - ptr1 + 1);
                break;
            }
        }
    }

    printf("%d", ans);
    return 0;
}