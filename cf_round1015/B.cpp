    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll gcd(ll a, ll b){
        return b == 0 ? a : gcd(b, a % b);
    }

    void solve(){
        int n;
        cin >> n;
        vector<ll> nums(n);
        for(int i = 0; i < n; ++i){
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        ll ans = nums[0];
        vector<ll> temp;
        sort(temp.begin(), temp.end());
        for(int i = 1; i < n; ++i){
            if(nums[i] % ans == 0){
                temp.push_back(nums[i] / ans);
            }
        } 
        if(temp.size() == 0){
            cout << "No" << endl;
        }
        else if(temp.size() == 1){
            if(temp[0] == 1){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
            ll r = gcd(temp[0], temp[1]);
            for(int i = 2; i < temp.size(); ++i){
                r = gcd(r, temp[i]);
            }
            if(r == 1){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        return;
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