#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    // L : 1, I : 2, T : 3
    int gap1 = 0, gap2 = 0, gap3 = 0;
    int num1 = 0, num2 = 0, num3 = 0;
    vector<int> gap(n);
    for(int i = 0; i < n - 1; ++i){
        if((s[i] == 'L' && s[i + 1] == 'I') || (s[i] == 'I' && s[i + 1] == 'L')){
            gap3++;
            gap[i] = 3;
        }
        else if((s[i] == 'L' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'L')){
            gap2++;
            gap[i] = 2;
        }
        else if((s[i] == 'I' && s[i + 1] == 'T') || (s[i] == 'T' && s[i + 1] == 'I')){
            gap1++;
            gap[i] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(s[i] == 'L') num1++;
        else if(s[i] == 'I') num2++;
        else num3++;
    }
    if(num1 == num2 && num2 == num3) cout << 0 << endl;
    else if(num1 == num2 && num2 > num3){
        if(gap3 < num2 - num3) cout << -1 << endl;
        else{
            int cnt = 0;
            vector<int> ans;
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 3){
                    cnt++;
                    ans.push_back(i + cnt);
                }
            }
            cout << cnt << endl;
            for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
    }
    else if(num1 == num3 && num3 > num2){
        if(gap2 < num3 - num2) cout << -1 << endl;
        else{
            int cnt = 0;
            vector<int> ans;
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 2){
                    cnt++;
                    ans.push_back(i + cnt);
                }
            }
            cout << cnt << endl;
            for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
    }
    else if(num2 == num3 && num2 > num1){
        if(gap1 < num2 - num1) cout << -1 << endl;
        else{
            int cnt = 0;
            vector<int> ans;
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 1){
                    cnt++;
                    ans.push_back(i + cnt);
                }
            }
            cout << cnt << endl;
            for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
    }

    else if(num3 >= num2 && num3 >= num1){
        int cnt = 0, cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        if(num2 >= num1){
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 1){
                    while(cnt2 + num2 < num3){
                        cnt++; cnt2++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt1 + num1 < num3){
                        cnt++;
                        cnt1++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 2){
                    while(cnt2 + num2 < num3){
                        cnt++; cnt2++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt2 + num2 < num3){
                        cnt++;
                        cnt2++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        else{
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 2){
                    while(cnt1 + num1 < num3){
                        cnt++; cnt2++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt2 + num2 < num3){
                        cnt++;
                        cnt2++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 1){
                    while(cnt1 + num1 < num3){
                        cnt++; cnt2++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt1 + num1 < num3){
                        cnt++;
                        cnt1++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        num2 += cnt2;
        num1 += cnt1;
        if(num1 == num3 && num2 == num3){
        cout << cnt << endl;
        for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    else if(num2 >= num1 && num2 >= num3){
        int cnt = 0, cnt1 = 0, cnt3 = 0;
        vector<int> ans;
        if(num3 >= num1){
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 1){
                    while(cnt3 + num3 < num2){
                        cnt++; cnt3++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt1 + num1 < num2){
                        cnt++;
                        cnt1++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 3){
                    while(cnt3 + num3 < num2){
                        cnt++; cnt3++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt3 + num3 < num2){
                        cnt++;
                        cnt3++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        else{
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 3){
                    while(cnt1 + num1 < num3){
                        cnt++; cnt3++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt3 + num3 < num2){
                        cnt++;
                        cnt3++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 1){
                    while(cnt1 + num1 < num3){
                        cnt++; cnt3++; cnt1++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + i);
                    }
                    if(cnt1 + num1 < num3){
                        cnt++;
                        cnt1++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        num3 += cnt3;
        num1 += cnt1;
        if(num1 == num2 && num2 == num3){
        cout << cnt << endl;
        for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    else{
        int cnt = 0, cnt3 = 0, cnt2 = 0;
        vector<int> ans;
        if(num2 >= num3){
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 3){
                    while(cnt2 + num2 < num1){
                        cnt++; cnt2++; cnt3++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt3 + num3 < num1){
                        cnt++;
                        cnt3++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 2){
                    while(cnt2 + num2 < num1){
                        cnt++; cnt2++; cnt3++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt2 + num2 < num1){
                        cnt++;
                        cnt2++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        else{
            for(int i = 0; i < n - 1; ++i){
                if(gap[i] == 2){
                    while(cnt3 + num3 < num1){
                        cnt++; cnt2++; cnt3++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt2 + num2 < num1){
                        cnt++;
                        cnt2++;
                        ans.push_back(cnt + i);
                    }
                }
                if(gap[i] == 3){
                    while(cnt3 + num3 < num1){
                        cnt++; cnt2++; cnt3++;
                        ans.push_back(cnt + i); cnt++; ans.push_back(cnt + 1 + i);
                    }
                    if(cnt3 + num3 < num1){
                        cnt++;
                        cnt3++;
                        ans.push_back(cnt + i);
                    }
                }
            }
        }
        num2 += cnt2;
        num3 += cnt3;
        if(num1 == num3 && num2 == num3){
        cout << cnt << endl;
        for(int i = 0; i < cnt; ++i) cout << ans[i] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
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