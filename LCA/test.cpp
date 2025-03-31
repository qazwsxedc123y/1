#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 5e5 + 10;
int n, m, s;
vector<int> g[N];
int dep[N], fa[N][20];
// dep[u]��u������
// fa[u][i] ��� u�������� 2' ������Ƚ��

void dfs(int u, int father) {
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    // ������һ��
    for (auto v : g[u]) {
        if (v != father) dfs(v, u);
    }
}

int lca(int u, int v) {
    // ȷ��u������Ǵ��
    if (dep[u] < dep[v]) swap(u, v);
    //������ͬһ��
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    }
    // ���ˣ�������ͬһ�ڵ�
    if (u == v) return u;
    //������LCA����һ��
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