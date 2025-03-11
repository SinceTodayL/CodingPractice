#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int a[7] = {0};
    for(int i = 0; i < 8; ++i){
        char ch = s[i];
        if(ch == 'n'){
            a[0] += 1;
        }
        else if(ch == 'o'){
            a[1] += 1;
        }
        else if(ch == 'w'){
            a[2] += 1;
        }
        else if(ch == 'c'){
            a[3] += 1;
        }
        else if(ch == 'o'){
            a[1] += 1;
        }
        else if(ch == 'd'){
            a[4] += 1;
        }
        else if(ch == 'e'){
            a[5] = 1;
        }
        else if(ch == 'r'){
            a[6] = 1;
        }
    }
    bool flag = true;
    for(int i = 0; i <= 6; ++i){
        if(i == 1){
            if(a[i] != 2){
                flag = false;
                break;
            }
        }
        else{
            if(a[i] != 1){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << "happy new year" << endl;
    }
    else{
        cout << "I AK IOI" << endl;
    }
    return 0;
}