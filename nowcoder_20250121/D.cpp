#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    if( n % 2 != 0){
        cout << "No" << endl;
        return;
    }
    int cate = 0;
    int temp1 = 0, temp2 = 0;
    int times1 = 0, times2 = 0;
    for(int i = 1; i <= n; ++i){
        if(cate == 0){
            temp1 = nums[i];
            cate = 1;
            times1++;
        }
        else if(cate == 1){
            if(temp1 != nums[i]){
                cate++;
                temp2 = nums[i];
                times2++;
            }
            else{
                times1++;
            }
        }
        else{
            if(temp1 != nums[i] && temp2 != nums[i]){
                cout << "No" << endl;
                return;
            }
            else if(temp1 == nums[i]){
                times1++;
            }
            else{
                times2++;
            }
        }
    }
    if(cate == 2 && times1 == times2)
        cout << "Yes" << endl;
    else
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