#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
struct node{
    double a, b, y;
}point[1010];
bool cmp(node& l, node& r){
    return l.y > r.y;
}

bool check(double k){
      for(int i = 0; i < n; ++i){
          point[i].y = - point[i].b * k + point[i].a * 1.0;
      }
      sort(point, point + n, cmp);
      double all = 0;
      for(int i = 0; i < n - t; ++i){
           all += point[i].y;
      }
      return all - 0 > 1e-6;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> n >> t;
        if(n == 0 && t == 0){
            break;
        }
        double l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            cin >> point[i].a;
            r += point[i].a;
        }
        for(int i = 0; i < n; ++i){
            cin >> point[i].b;
        }
        while(fabs(r - l) > 1e-6){
             double mid = (r - l)/2 + l;
             if(check(mid)){
                l = mid;
             } 
             else{
                r = mid;
             }
        }
        int ans = static_cast<int>(100.0 * l + 0.5);
        cout << ans << endl;
    }
    
    return 0;
}