    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void solve(){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        cout << nums[n - 1] - nums[0] << endl;
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