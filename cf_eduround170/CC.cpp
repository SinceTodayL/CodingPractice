#include <bits/stdc++.h>
using namespace std;

struct node {
    int key, value;
    node(int x, int y) {
        key = x;
        value = y;
    }
};
bool cmp(node a, node b) {
    return a.key < b.key;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    unordered_map<int, int> mp;
    vector<node> vec;

    while (t--) {
        mp.clear();
        vec.clear();
        int n, k, tmp;
        cin >> n >> k;

        // 统计每个数字出现的次数
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mp[tmp]++;
        }

        // 将哈希表内容转为 vector 并排序
        for (auto ele : mp) {
            vec.push_back(node(ele.first, ele.second));
        }
        sort(vec.begin(), vec.end(), cmp);

        int fp = 0, bp = 0, last = 0, ans = 0;

        // 初始化第一个窗口的和
        while (fp < vec.size() && fp - bp < k) {
            last += vec[fp].value;
            fp++;
        }

        ans = max(ans, last);

        // 双指针遍历
        while (fp < vec.size()) {
            // 如果两个数字连续，继续增加右边界
            while (fp < vec.size() && vec[fp].key - vec[fp - 1].key == 1) {
                last += vec[fp].value;
                fp++;
            }

            ans = max(ans, last);

            // 缩小窗口，直到窗口大小变小于 k
            while (fp - bp >= k && bp < fp) {
                last -= vec[bp].value;
                bp++;
            }

            // 再次更新答案
            ans = max(ans, last);
        }

        cout << ans << endl;
    }

    return 0;
}

