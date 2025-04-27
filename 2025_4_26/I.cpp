#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b;
set<int> numsa, numsb;
bool check(int x, int leftb){
    if(leftb < 0){
        return false;
    }
    if(x <= 0){
        if(leftb == 0){
            return true;
        }
        else{
            return false;
        }
    }
    return check(x - 1, leftb - 2) || check(x - 1, leftb - 3) ||
           check(x - 1, leftb - 5) || check(x - 1, leftb - 6);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;
    if(a <= 3)
        numsa.insert(a);
    if(a % 4 == 0 && a <= 12){
        numsa.insert(a / 4);
    }
    if(a == 5){
        numsa.insert(2);
    }
    if(a == 9 || a == 6){
        numsa.insert(3);
    }
    if(numsa.empty()){
        cout << "No" << endl;
        return 0;
    }
    for(int ele : numsa){
        if(ele > 3){
            cout << "No" << endl;
            return 0;
        }
        if(check(3 - ele, b)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}