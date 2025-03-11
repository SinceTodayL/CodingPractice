#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll m1 = 4e8;
const ll m2 = 4e8-1;
const ll M = m1*m2;


//��չŷ������㷨 
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long crt(long long r1, long long r2) {
    long long x, y;
    
    // �� m1 �� m2 ��ģ��
    extended_gcd(m1, m2, x, y);
    long long inv1 =x;
    
    // �� m2 �� m1 ��ģ��
    extended_gcd(m2, m1, x, y);
    long long inv2 =x;
    
    // �����й�ʣ�ඨ��ʽ�ϲ�
    return ((r1 * inv2 * m2 + r2 * inv1 * m1) % M + M)%M;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    	ll rc1, rc2;
    	cout<<"? "<<m1<<endl;
    	cout.flush();
    	cin>>rc1;
    	if(rc1==-1) return 0;
    	cout<<"? "<<m2<<endl;
    	cout.flush();
    	cin>>rc2;
    	if(rc2==-1) return 0;
    	cout<<"! "<<crt(rc1, rc2)<<endl;
	}
    return 0;
}

/*
int main(){
	int t;
	cin>>t;
	while(t--){
		ll rc1, rc2;
		cout<<"? "<<m1<<endl;
		cin>>rc1;
		cout<<"? "<<m2<<endl;
		cin>>rc2;
		if(rc2==rc1)
		cout<<"! "<<(rc2-rc1)*m1+rc1<<endl;
		else{
			cout<<"! "<<((rc2-rc1+m1-1)*m1+rc1)%M<<endl;
		}
	}
	return 0;
}
*/
