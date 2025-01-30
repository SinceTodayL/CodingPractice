#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int xb, yb, xm, ym;
ll dp[25][25];
bool flag[25][25];

int main()
{
    cin >> yb >> xb >> ym >> xm;
    for(int i = 0; i <= yb; ++i)
        for(int j = 0; j <= xb; ++j){
            flag[i][j] = true;
            dp[i][j] = 0;
        }
    flag[ym][xm] = false;
    if(ym >= 2 && xm >= 1)
        flag[ym-2][xm-1] = false;
    if(ym >= 1 && xm >= 2)
        flag[ym-1][xm-2] = false;
    if(xm >= 2)
        flag[ym+1][xm-2] = false;
    if(xm >= 1)
        flag[ym+2][xm-1] = false;
    if(ym >= 2)
        flag[ym-2][xm+1] = false;
    if(ym >= 1)
        flag[ym-1][xm+2] = false;
    flag[ym+1][xm+2] = false;
    flag[ym+2][xm+1] = false;
    for(int i = 0; i <= yb; ++i){
        if(!flag[i][0])
            break;
        dp[i][0] = 1;
    }
    for(int j = 0; j <= xb; ++j){
        if(!flag[0][j])
            break;
        dp[0][j] = 1;
    }
    flag[0][0] = 0;
    for(int i = 1; i <= yb; ++i)
        for(int j = 1; j <= xb; ++j){
        	if(!flag[i][j])
        	    dp[i][j] = 0;
        	else
        	    dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	cout << dp[yb][xb];
    return 0;
}

