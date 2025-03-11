#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int p,q,a1,a2,n,m;
struct mat{
	ll ele[2][2];
	mat operator*(const mat& other){
		mat res;
		memset(res.ele, 0, sizeof(res.ele));
		for(int i=0; i<2; ++i){
			for(int j=0; j<2; ++j){
				for(int k=0; k<2; ++k){
					res.ele[i][j]= (res.ele[i][j] + (this->ele[i][k]*other.ele[k][j]))%m;
				}
			}
		}
		return res;
	}
};

mat fp(mat matrix ,int exp){
	mat res;
	memset(res.ele, 0, sizeof(res.ele));
	for(int i=0; i<2; ++i)
	    res.ele[i][i]=1;
     while(exp){
     	if(exp&1) res = res*matrix;
     	matrix = matrix*matrix;
     	exp>>=1;
	 }
	 return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>p>>q>>a1>>a2>>n>>m;
    if(n == 1){
    	cout<<a1<<endl;return 0;
	}
	if(n==2){
		cout<<a2<<endl; return 0;
	}
    mat matrix;
    matrix.ele[0][0]=p; matrix.ele[0][1]=1; matrix.ele[1][0]=q; matrix.ele[1][1]=0;
    matrix = fp(matrix, n-2);

    ll ans=0;
    ans = ((a2*matrix.ele[0][0]) + (a1*matrix.ele[1][0])) %m;
    cout<<ans;
    
    return 0;
}

