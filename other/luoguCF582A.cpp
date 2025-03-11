#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map<int, int> mp;

inline int gcd(int x, int y){
    return (y == 0) ? x : gcd(y, x % y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums;
    vector<int> ans;
    cin >> n;
    int input;
    for(int i = 1; i <= n * n; ++i){
        cin >> input;
        mp[input]++;
    }
    nums.push_back(0);
    for(auto ele : mp){
        nums.push_back(ele.first);
    }
    sort(nums.begin(), nums.end());
    int len = nums.size() - 1;
    int max1 = nums[len], max2;
    ans.push_back(max1);
    mp[max1]--;

    while(len >= 1){
        while(len >= 1 && mp[nums[len]] == 0){
            len--;
        }
        max2 = nums[len];
        mp[max2]--;

        for(int ele : ans){
            mp[gcd(ele, max2)] -= 2;
        }
        ans.push_back(max2);
    }


    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}