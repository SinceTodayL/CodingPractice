#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[125][125] = {0}; 
int prefix_num[125][125] = {0};
int n;
int max_sum = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            scanf("%d", &num[i][j]);
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            prefix_num[i][j] = prefix_num[i-1][j] + prefix_num[i][j-1] - prefix_num[i-1][j-1] + num[i][j];
    
    for(int f_x = 1; f_x <= n; ++f_x)
        for(int f_y = 1; f_y <= n; ++f_y)
            for(int b_x = 1; b_x <= f_x; ++b_x)
                for(int b_y = 1; b_y <= f_y; ++b_y)
                {
                	max_sum = max(max_sum, prefix_num[f_x][f_y] - prefix_num[b_x - 1][f_y] - prefix_num[f_x][b_y - 1] + prefix_num[b_x-1][b_y-1]);
				}
    
    cout<<max_sum;
    return 0;
}

