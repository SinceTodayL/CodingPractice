#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> note;
vector<string> song;
int n, m;

bool check(const string& s){
    for(int i = 1; i <= m; ++i){
        int cur = 0;
        for(int j = 0; j < s.size(); ++j){
            int index = j;
            cur = 0;
            while(note[i][cur] == s[index]){
                cur++;
                index++;
                if(cur == note[i].size()){
                    return true;
                }
                if(j >= s.size()){
                    break;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    song.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> song[i];
    }
    cin >> m;
    note.resize(m + 1);
    for(int i = 1; i <= m; ++i){
        cin >> note[i];
    }

    for(int i = 1; i <= n; ++i){
        if(check(song[i])){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}