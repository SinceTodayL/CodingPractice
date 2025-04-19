#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
// 节点个数
const int N = 4;
// 从 1 到 4 的距离矩阵（对称）
int dist[N+1][N+1] = {
    {INF, INF, INF, INF, INF},
    {INF,   0,  30,   6,   4},  // dist[1][2]=30, dist[1][3]=6, dist[1][4]=4
    {INF,  30,   0,   5,  10},  // dist[2][3]=5,  dist[2][4]=10
    {INF,   6,   5,   0,  20},  // dist[3][4]=20
    {INF,   4,  10,  20,   0}
};

int bestCost = INF;
vector<int> path;                 // 当前环路（不含起点1）
vector<bool> used(N+1, false);    // 标记 2..4 是否已被访问
vector<vector<int>> bestPaths;    // 所有最优环路

// u: 当前所在节点；depth: 当前深度(已访问节点数，包括起点1)；cost: 累计花费
void dfs(int u, int depth, int cost) {
    // 剪枝：已超过当前最优
    if (cost > bestCost) return;

    if (depth == N) {
        // 回到起点 1
        cost += dist[u][1];
        if (cost < bestCost) {
            bestCost = cost;
            bestPaths.clear();
            bestPaths.push_back(path);
        }
        else if (cost == bestCost) {
            bestPaths.push_back(path);
        }
        return;
    }

    // 枚举下一个要访问的节点 v
    for (int v = 2; v <= N; ++v) {
        if (!used[v]) {
            used[v] = true;
            path.push_back(v);
            dfs(v, depth + 1, cost + dist[u][v]);
            path.pop_back();
            used[v] = false;
        }
    }
}

int main() {
    // 从 1 号点出发
    used.assign(N+1, false);
    path.clear();
    dfs(1, 1, 0);

    // 输出结果
    cout << "最优环路花费 = " << bestCost << "\n";
    cout << "所有最优环路：\n";
    for (auto &p : bestPaths) {
        // 打印形式如 1→3→2→4→1，对应字符串 "13241"
        cout << "  ";
        cout << 1;
        for (int v : p) cout << v;
        cout << 1 << "\n";
    }
    return 0;
}
