#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+9;
const ll INF=(1LL<<60)-1;
const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};

int n,m,t[N],d[N];

inline int Encode(int x,int y){return (x-1)*m+y;}
inline pair<int,int> Decode(int index){return make_pair((index-1)/m+1,(index-1)%m+1);}

void Read(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>t[Encode(i,j)];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>d[Encode(i,j)];
}

ll dis[N][4];
bool vis[N][4];

void Dijkstra(){
    int st=Encode(1,1);
    int ed=Encode(n,m);
    for(int i=1;i<=n*m;++i)
        for(int j=0;j<4;++j){
            dis[i][j]=INF;
            vis[i][j]=false;
        }
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>,
    std::greater<tuple<ll,int,int>>> pq;
    dis[st][0]=t[st];
    pq.emplace(0,st,0);

    for(;!pq.empty();){
        auto [val,p,u]=pq.top();
        pq.pop();
        if(vis[p][u])   continue;
        vis[p][u]=true;
        for(int i=0;i<4;++i){
            if(dis[p][u]+d[p]>=dis[p][i])   continue;
            dis[p][i]=dis[p][u]+d[p];
            pq.emplace(dis[p][i],p,i);
        }
        auto [x,y]=Decode(p);
        x+=dx[u]; y+=dy[u];
        int q=Encode(x,y);
        auto OutMap=[&](int x,int y){
            return x<1||x>n||y<1||y>n;
        };
        if(!OutMap(x,y) && dis[p][u]+t[q]<dis[q][u]){
            dis[q][u]=dis[p][u]+t[q];
            pq.emplace(dis[q][u],q,u);
        }
    }
    cout<<dis[ed][3]<<endl;
}

void solve(){
    Read();
    Dijkstra();
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