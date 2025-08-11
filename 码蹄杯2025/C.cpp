#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(const vector<vector<int>> &tree, vector<int> &son_number, int index, int father)
{
    for (int idx : tree[index])
    {
        if (idx != father)
        {
            dfs(tree, son_number, idx, index);
            son_number[index] += son_number[idx];
        }
    }
}

ll ans = 0, cnt = 0;

void solve(const vector<vector<int>> &tree, vector<int> &son_number, int index, int father)
{
    if (son_number[index] == 1)
    {
        cnt += 1;
        ans = max(ans, cnt);
        cnt -= 1;
        return;
    }
    for (int idx : tree[index])
    {
        if (idx != father)
        {
            cnt += son_number[index];
            solve(tree, son_number, idx, index);
            cnt -= son_number[index];
        }
    }
}

int main()
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    vector<int> son_number(n + 1, 1);
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(tree, son_number, 1, 0);
    solve(tree, son_number, 1, 0);
    cout << ans << endl;
    return 0;
}