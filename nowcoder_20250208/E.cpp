#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    char chess[3][3];
    int left = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> chess[i][j];
            if(chess[i][j] == 'G'){
                left++;
            }
        }
    }
    if(left == 9){
        cout << "Yes" << endl;
        return;
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(chess[i][j] == 'X'){
                int blank = 0, my = 0;
                // 1.
                for(int k = 0; k < 3; ++k){
                    if(chess[i][k] == 'G'){
                        blank++;
                    }
                    else if(chess[i][k] == 'X'){
                        my++;
                    }
                }
                if(blank + my == 3){
                    cout << "Yes" << endl;
                    return;
                }
                // 2.
                blank = 0; my = 0;
                for(int k = 0; k < 3; ++k){
                    if(chess[k][j] == 'G'){
                        blank++;
                    }
                    else if(chess[k][j] == 'X'){
                        my++;
                    }
                }
                if(blank + my == 3){
                    cout << "Yes" << endl;
                    return;
                }
                // 3.
                blank = 0; my = 0;
                int constant = i - j;
                for(int k = max(0, constant); k < min(3, 3 - constant); ++k){
                    if(chess[k][k - constant] == 'G'){
                        blank++;
                    }
                    else if(chess[k][k - constant] == 'X'){
                        my++;
                    }
                }
                if(blank + my == 3){
                    cout << "Yes" << endl;
                    return;
                }
                // 4.
                blank = 0; my = 0;
                constant = i + j;
                for(int k = min(2, constant); k >= max(0, constant - 2) ; --k){
                    if(chess[k][constant - k] == 'G'){
                        blank++;
                    }
                    else if(chess[k][constant - k] == 'X'){
                        my++;
                    }
                }
                if(blank + my == 3){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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