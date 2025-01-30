#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int ans[500];
int ansbit=0,ansnum=1;
int cnt=0;
int bitget[30],bitnum,num1;
void getnum1(int x){
    bitnum=0; num1=0;
    while(x>0){
        bitget[bitnum++]=x&1;
        if(x&1){
            ++num1;
        }
        x>>=1;
    }
    return ;
}
int main(){
    bool tag=false;
    int k;
    cin >> k;

    if(k==1){
        printf("6\n1 1 4 5 1 4\n");
        return 0;
    }
    if(k == 0){
        printf("5\n2 5 1 4 3\n");
        return 0;
    }
    /*
    if(k==3){
        printf("3\n1 1 2\n");
        return 0;
    }
    */
    int nowneed=k;
    while(1){
        getnum1(nowneed);
        if(!tag || nowneed==1)
            nowneed=num1-1;
        else    
            nowneed=num1;
        tag = true;
        for(int i=bitnum-1;i>=0;--i){
            if(bitget[i]==1){
                if(i>=1)
                    for(int j=1;j<=i;++j)
                        ans[++ansbit]=ansnum;
                else
                    ans[++ansbit]=ansnum;
                ++ansnum;
            }
        }
        if(ansbit>365){
            printf("-1");
            return 0;
        }
        if(nowneed==0)
            break;
    }
    printf("%d\n",ansbit);
    for(int i=1;i<=ansbit;++i)
        printf("%d ",ans[i]);
    return 0;
}

/*
int two[31];
int fp(int a, int n){
    int ans = 1;
    while(n){
        if(n & 1){
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

int ans[366];

int main(){

    int k;
    int cnt = 1;
    int num = 1;
    cin >> k;
    if(k == 1){
        cout << 6 << endl;
        cout << "1 1 4 5 1 4" << endl;
        return 0;
    }
    if(k == 0){
        cout << 5 << endl;
        cout << "2 5 1 4 3" << endl;
        return 0;
    }
    for(int i = 0; i <= 31; ++i){
        two[i] = fp(2, i);
    }
    while(1){
        int temp = upper_bound(two, two + 32, k) - two;
        for(int i = 1; i < temp; ++i){
            ans[cnt++] = num;
        }
        num++;
        k -= two[temp - 1];
        if(k <= 0){
            break;
        }
        k++;
    }
    cout << cnt - 1 << endl;
    for(int i = 1; i < cnt; ++i){
        cout << ans[i] << " ";
    }
    return 0;
}
*/