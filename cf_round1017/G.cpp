#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll score = 0, rscore = 0;
    ll sum = 0, s = 0;
    deque<int> qp, qn;
    int q;
    cin >> q;
    while(q--){
        int choice;
        cin >> choice;
        if(choice == 3){
            int input;
            cin >> input;
            sum += input;
            s++;    
            qp.push_back(input);
            qn.push_front(input);
            rscore += sum;
            score += s * input;

        }
        else if(choice == 2){
           swap(rscore, score);
           swap(qp, qn);
        }
        else{
            int last = qp.back();
            qp.pop_back();
            qp.push_front(last);
            score -= s * last;
            score += sum;

            last = qn.front();
            qn.pop_front();
            qn.push_back(last);
            rscore -= sum;
            rscore += s * last;
        }
        cout << score << endl;
    }
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