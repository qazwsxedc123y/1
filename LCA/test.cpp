#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 5e5 + 10;
int n, m, s;
vector<int> g[N];
int dep[N], fa[N][20];
// dep[u]存u点的深度
// fa[u][i] 存从 u点向上跳 2' 层的祖先结点

void dfs(int u, int father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    // 遍历下一组
    for (auto v : g[u]) {
        if (v != father) dfs(v, u);
    }
}

int lca(int u, int v) {
    // 确保u的深度是大的
    if (dep[u] < dep[v]) swap(u, v);
    //先跳到同一层
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    }
    // 巧了，正好是同一节点
    if (u == v) return u;
    //再跳到LCA的下一层
    for (int i = 19; i >= 0; i--)
    {
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    }
    return fa[u][0];
}

int main()
{
    cin >> n >> m >> s;
    for (int i = 1, x, y; i < n; ++i)
    {
        cin >> x >> y;
        g[x].emplace_back(y), g[y].emplace_back(x);
    }
    dfs(s, 0);
    for (int x, y; m > 0; m--)
    {
        cin >> x >> y;
        cout << lca(x, y) << endl;;
    }
    return 0;
}