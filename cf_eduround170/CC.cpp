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

        // ͳ��ÿ�����ֳ��ֵĴ���
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mp[tmp]++;
        }

        // ����ϣ������תΪ vector ������
        for (auto ele : mp) {
            vec.push_back(node(ele.first, ele.second));
        }
        sort(vec.begin(), vec.end(), cmp);

        int fp = 0, bp = 0, last = 0, ans = 0;

        // ��ʼ����һ�����ڵĺ�
        while (fp < vec.size() && fp - bp < k) {
            last += vec[fp].value;
            fp++;
        }

        ans = max(ans, last);

        // ˫ָ�����
        while (fp < vec.size()) {
            // ��������������������������ұ߽�
            while (fp < vec.size() && vec[fp].key - vec[fp - 1].key == 1) {
                last += vec[fp].value;
                fp++;
            }

            ans = max(ans, last);

            // ��С���ڣ�ֱ�����ڴ�С��С�� k
            while (fp - bp >= k && bp < fp) {
                last -= vec[bp].value;
                bp++;
            }

            // �ٴθ��´�
            ans = max(ans, last);
        }

        cout << ans << endl;
    }

    return 0;
}

