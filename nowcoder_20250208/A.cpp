#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll num;
    char ch;
    cin >> num >> ch;
    if(ch == '*'){
        cout << 1 << " " << num << endl;
    }
    else if(ch == '+'){
        cout << 1 << " " << num - 1 << endl;
    }
    else{
        cout << num + 1 << " " << 1 << endl;
    }

    return 0;
}