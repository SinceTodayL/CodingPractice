#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
struct node{
    int a, b;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<node> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].a >> p[i].b;
        p[i].a *= 2;
        p[i].b *= 2;
    }
    double l = 0, r = 2e4;
    while()

    return 0;
}