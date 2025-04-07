#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 65;
const int maxn = 3205;
vector<vector<int>> w(N, vector<int>(3, 0));
vector<vector<int>> value(N, vector<int>(3, 0));
vector<int> _size(N, 0);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v, q, p;
    cin >> n >> m;
    n /= 10;
    for(int i = 1; i <= m; ++i){
        cin >> v >> p >> q;
        if(q == 0){
            w[i][0] = p;
            value[i][0] = v / 10;
            _size[i]++;
        }
        else{
            w[q][w[q][0] == 0 ? _size[q] + 1 : _size[q]] = p;
            value[q][w[q][0] == 0 ? _size[q] + 1 : _size[q]] = v / 10;
            _size[q]++;
        }
    }
    vector<int> dp(maxn, 0);
    for(int i = 1; i <= m; ++i){
        for(int j = n; j >= 1; --j){
            if(_size[i] >= 1 && j >= value[i][0]){
                dp[j] = max(dp[j], dp[j - value[i][0]] + w[i][0] * value[i][0]);
            }
            if(_size[i] >= 2 && j >= value[i][1] + value[i][0]){
                dp[j] = max(dp[j], dp[j - value[i][0] - value[i][1]] + w[i][0] * value[i][0] + w[i][1] * value[i][1]);
            }
            if(_size[i] >= 3 && j >= value[i][0] + value[i][2]){
                dp[j] = max(dp[j], dp[j - value[i][0] - value[i][2]] + w[i][0] * value[i][0] + w[i][2] * value[i][2]);
            }
            if(_size[i] >= 3 && j >= value[i][1] + value[i][2] + value[i][0]){
                dp[j] = max(dp[j], dp[j - value[i][0] - value[i][1] - value[i][2]] + w[i][0] * value[i][0] + w[i][1] * value[i][1] + w[i][2] * value[i][2]);
            }
        }
    }

    cout << 10 * dp[n] << endl;
    return 0;
}