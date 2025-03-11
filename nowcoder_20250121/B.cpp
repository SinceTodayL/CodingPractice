#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 1;
int n;
int point[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int input1, input2;
    for(int i = 1; i <= n - 1; ++i){
        cin >> input1 >> input2;
        point[input1]++;
        point[input2]++;
    }
    bool flag = true;
    int cnt = 0;
    int st = 0, ed = 0;
    for(int i = 1; i <= n; ++i){
        if(point[i] == 1 && cnt <= 2){
            cnt++;
            if(cnt == 1){
                st = i;
            }
            else{
                ed = i;
            }
        }
        else if(point[i] != 1 && point[i] != 2){
            flag = false;
            break;
        }

        else if(point[i] != 2){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << st << " " << ed << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}