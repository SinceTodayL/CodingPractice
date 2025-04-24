#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;
int n;
vector<int> a(MAXN), p(MAXN);

void construct(const vector<int>& pos, vector<int> nums, int layer) {
    sort(nums.begin(), nums.end());

    if (pos.size() == 1) {
        p[pos[0]] = nums[0];
        return;
    }

    vector<int> keep;
    for (int x : pos) {
        if (a[x] > layer) {
            keep.push_back(x);
        }
    }

    if (layer % 2 == 1) {
        reverse(nums.begin(), nums.end());
    }

    vector<int> newNums;
    for (size_t i = 0; i < keep.size(); ++i) {
        newNums.push_back(nums.back());
        nums.pop_back();
    }

    construct(keep, newNums, layer + 1);

    reverse(nums.begin(), nums.end());

    int last = -1;
    for (int x : pos) {
        last = x;
        if (a[x] > layer) break;
        p[x] = nums.back();
        nums.pop_back();
    }

    reverse(nums.begin(), nums.end());

    for (int x : pos) {
        if (x < last || a[x] > layer) continue;
        p[x] = nums.back();
        nums.pop_back();
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= 0) a[i] = 1e9;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1); // [1, 2, ..., n]

    construct(indices, indices, 1);

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
