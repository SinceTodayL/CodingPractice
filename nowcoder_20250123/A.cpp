#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 7; ++i){
        int input;
        cin >> input;
        if(input != 1 && input != 2 && input != 3 && input != 5 && input != 6){
            cout << "No" << endl;
        }
    }
    cout << "Yes" << endl;

    return 0;
}