#include <bits/stdc++.h>
using namespace std;

struct SegTreeNode {
    int l, r;
    vector<int> pos_list;
    SegTreeNode *left, *right;
    SegTreeNode(int l_, int r_) : l(l_), r(r_), left(nullptr), right(nullptr) {}
};

SegTreeNode* build(int l, int r, const vector<int>& pos) {
    SegTreeNode* node = new SegTreeNode(l, r);
    if (l == r) {
        node->pos_list.push_back(pos[l]);
        return node;
    }
    int mid = (l + r) / 2;
    node->left = build(l, mid, pos);
    node->right = build(mid + 1, r, pos);
    node->pos_list.reserve(node->left->pos_list.size() + node->right->pos_list.size());
    merge(node->left->pos_list.begin(), node->left->pos_list.end(),
          node->right->pos_list.begin(), node->right->pos_list.end(),
          back_inserter(node->pos_list));
    return node;
}

int query(SegTreeNode* node, int y_max, int l_pos, int r_pos) {
    if (node->l > y_max || node->r < 1) {
        return 0;
    }
    if (node->r <= y_max) {
        auto& v = node->pos_list;
        int a = lower_bound(v.begin(), v.end(), l_pos) - v.begin();
        int b = upper_bound(v.begin(), v.end(), r_pos) - v.begin();
        return b - a;
    }
    return query(node->left, y_max, l_pos, r_pos) + query(node->right, y_max, l_pos, r_pos);
}

void deleteSegTree(SegTreeNode* node) {
    if (!node) return;
    deleteSegTree(node->left);
    deleteSegTree(node->right);
    delete node;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            int y = p[i];
            pos[y] = i + 1;
        }
        SegTreeNode* root = build(1, n, pos);
        while (m--) {
            int l, r, c;
            cin >> l >> r >> c;
            int x = p[c - 1];
            int y_max = x - 1;
            int k = 0;
            if (y_max >= 1) {
                k = query(root, y_max, l, r);
            }
            cout << l + k << '\n';
        }
        deleteSegTree(root);
    }
    return 0;
}