#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    cout << nums[n / 2 + 1] - 1 << endl;

    return 0;
}