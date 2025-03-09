#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a(8);
    for(int i = 0; i < 8; ++i){
        cin >> a[i];
    }
    int col = 0, row = 0;
    // col
    for(int i = 0; i < 8; ++i){
        bool flag = true;
        for(int j = 0; j < 8; ++j){
            if(a[i][j] != 'B'){
                flag = false;
                break;
            }
        }
        if(flag){
            col++;
        }
    }
    // row
    for(int i = 0; i < 8; ++i){
        bool flag = true;
        for(int j = 0; j < 8; ++j){
            if(a[j][i] != 'B'){
                flag = false;
                break;
            }
        }
        if(flag){
            row++;
        }
    }
    cout << row + col << endl;
    return 0;
}