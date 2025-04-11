#include <bits/stdc++.h>
using namespace std;
 
void sort3(int *num, int size) {
    if (size == 1) {
        // 数组大小为1，无需排序 
        return;
    } else if (size == 2) {
        // 数组大小为2，只需比较一次 
        if (num[0] > num[1]) {
            int temp = num[0];
            num[0] = num[1];
            num[1] = temp;
        }
    } else if (size == 3) {
        // 数组大小为3，进行三次比较 
        if (num[0] > num[1]) {
            int temp = num[0];
            num[0] = num[1];
            num[1] = temp;
        }
        if (num[1] > num[2]) {
            int temp = num[1];
            num[1] = num[2];
            num[2] = temp;
        }
        if (num[0] > num[1]) {
            int temp = num[0];
            num[0] = num[1];
            num[1] = temp;
        }
    }
}

void solve() {
    int n;
    scanf("%d", &n);
    int num[3], a[100], len = 0;

    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    sort3(num, 3);
    int possible[3], pcnt = 0;

    if ((num[2] - num[1]) % num[0] == 0)
        possible[pcnt++] = (num[2] - num[1]) / num[0];
    if ((num[2] - num[0]) % num[1] == 0)
        possible[pcnt++] = (num[2] - num[0]) / num[1];
    if ((num[1] - num[0]) % num[2] == 0)
        possible[pcnt++] = (num[1] - num[0]) / num[2];

    pcnt = unique(possible, possible + pcnt) - possible;
    len = pcnt;
    memcpy(a, possible, pcnt * sizeof(int));

    if (n == 1 && len == 1) {
        cout << a[0] << "\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &num[0], &num[1], &num[2]);
        sort3(num, 3);
        int curr[3], ccnt = 0;

        if ((num[2] - num[1]) % num[0] == 0)
            curr[ccnt++] = (num[2] - num[1]) / num[0];
        if ((num[2] - num[0]) % num[1] == 0)
            curr[ccnt++] = (num[2] - num[0]) / num[1];
        if ((num[1] - num[0]) % num[2] == 0)
            curr[ccnt++] = (num[1] - num[0]) / num[2];

        sort3(curr, ccnt);
        ccnt = unique(curr, curr + ccnt) - curr;
        int new_a[3], new_len = 0;

        for (int j = 0; j < len; ++j) 
            for (int k = 0; k < ccnt; ++k) 
                if (a[j] == curr[k]) {
                    new_a[new_len++] = a[j];
                    break;
                }

        len = new_len;
        memcpy(a, new_a, len * sizeof(int));

        if (len == 1) {
            cout << a[0] << "\n";
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}