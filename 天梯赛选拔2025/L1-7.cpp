#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isdig(char ch){
    if(ch >= '0' && ch <= '9'){
        return true;
    }
    return false;
}
bool isalp(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    return false;
}
int b1, b2, b3;

void output(const string& part){
    char a1 = part[0];
    char a2 = part[1];
    char a3 = part[2];
    if(part.size() != 3 || a2 != '-'){
        cout << "Error Para!" << endl;
        return;
    }
    if((isdig(a1) && isdig(a3) && a3 > a1) || (isalp(a1) && isalp(a3) && a3 > a1)){
        string ans;
        string temp;
        for(int i = 1; i < int(a3 - a1); ++i){
            temp.push_back(char(a1 + i));
        }
        if(b1 == 2 && (isalp(a1))){
        
            for(char& ch : temp){
                ch += ('A' - 'a');
                }
        }
        if(b1 == 3){
            for(char& ch: temp){
                ch = '*';
            }
        }
        for(int i = 0; i < int(temp.size()); ++i){
            for(int j = 0; j < b2; ++j){
                ans.push_back(temp[i]);
            }
        }
        if(b3 == 1){
            cout << ans;
        }
        else{
            reverse(ans.begin(), ans.end());
            cout << ans;
        }
        
    }
    else{
        cout << '-';
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> b1 >> b2 >> b3;
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0; i < len; ++i){
        if(i != len - 1 && s[i + 1] != '-'){
            cout << s[i];
        }
        else{
            cout << s[i];
            if(i <= len - 3){
                output(s.substr(i, 3));
                i+=1;
            }
        }
    }

    return 0;
}