#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 1;
int n, k;
struct node{
    int index;
    int value;
    int father;
}a[N];

inline int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x % y); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].value;
        a[i].index = i;
        a[i].father = 0;  
    }
    int input1, input2, choice, temp;
    for(int i = 1; i <= n - 1; ++i){
        cin >> input1 >> input2;
        a[input2].father = input1;
    }

    for(int i = 1; i <= k; ++i){
        cin >> choice;
        bool flag = false;
        if(choice == 1){
            cin >> input1;
            temp = a[input1].father;
            while(temp != 0){
                if(gcd(a[input1].value, a[temp].value) != 1){
                    flag = true;
                    break;
                }
                temp = a[temp].father;
            }
            if(flag){
                cout << temp << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cin >> input1 >> input2;
            a[input1].value = input2;
        }
    }

    return 0;
}