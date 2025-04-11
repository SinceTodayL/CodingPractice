#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int max_n = 29;
 
struct node {
    int child[2] { -1, -1 };
    int last = -1;
};
 
//
int find(const vector<node>& trie, int value, int border) {
    int res = -1;
    int current = 0;
    bool ok = true;
    for (int position = max_n; ok && position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        int k_bit = (border >> position) & 1;
        auto& children = trie[current].child;
        if (k_bit == 1) {
            if (children[x_bit ^ 1] != -1) {
                current = children[x_bit ^ 1];
            } else {
                ok = false;
            }
        } else {
            if (children[x_bit ^ 1] != -1) {
                res = max(res, trie[children[x_bit ^ 1]].last);
            }
            if (children[x_bit] != -1) {
                current = children[x_bit];
            } else {
                ok = false;
            }
        }
    }
    if (ok) {
        res = max(res, trie[current].last);
    }
    return res;
}
 
void add(vector<node>& trie, int value, int index) {
    int current = 0;
    trie[current].last = max(trie[current].last, index);
    for (int position = max_n; position >= 0; position--) {
        int x_bit = (value >> position) & 1;
        if (trie[current].child[x_bit] == -1) {
            trie[current].child[x_bit] = trie.size();
            trie.push_back(node());
        }
        current = trie[current].child[x_bit];
        trie[current].last = max(trie[current].last, index);
    }
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    int ans = n + 1;
    vector<node> trie(1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(trie, x, i);
        int y = find(trie, x, k);
        if (y != -1) {
            ans = min(ans, i - y + 1);
        }
    }
 
    if (ans == n + 1) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}