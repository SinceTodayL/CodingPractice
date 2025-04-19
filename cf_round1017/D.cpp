#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size();
    int len2 = s2.size();
    vector<int> nums1(1, -1), nums2(1, -1);
    for(int i = 0; i < len1; ++i){
        if(i == len1 - 1){
            nums1.push_back(len1 - 1);
            break;
        }
        if(s1[i] != s1[i + 1]){
            nums1.push_back(i);
        }
    }
    for(int i = 0; i < len2; ++i){
        if(i == len2 - 1){
            nums2.push_back(len2 - 1);
            break;
        }
        if(s2[i] != s2[i + 1]){
            nums2.push_back(i);
        }
    }
    len1 = nums1.size();
    len2 = nums2.size();
    if(len1 != len2){
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i < len1; ++i){
        if((2 * (nums1[i] - nums1[i - 1]) < nums2[i] - nums2[i - 1]) || (1 * (nums1[i] - nums1[i - 1]) > nums2[i] - nums2[i - 1]) || (s1[nums1[i]] != s2[nums2[i]])){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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