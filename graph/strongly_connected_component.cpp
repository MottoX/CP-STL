struct Edge {
    int to, next;

    Edge() {}

    Edge(int _to, int _nxt) : to(_to), next(_nxt) {}
} edge[55555];

int idx = 1, head[N];

void addEdge(int u, int v) {
    edge[++idx] = Edge(v, head[u]);
    head[u] = idx;
}

int dfn[N], low[N], vis[N], scc[N], sccCnt, stk[N], stkTop;
int sccSize[N];

void dfs(int u, int &dep) {
    vis[u] = 1;
    low[u] = dfn[u] = dep;
    stk[++stkTop] = u;
    for (int k = head[u]; k; k = edge[k].next) {
        int v = edge[k].to;
        if (vis[v] == 0) {
            dfs(v, ++dep);
            low[u] = min(low[u], low[v]);
        } else if (vis[v] == 1)
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++sccCnt;
        sccSize[sccCnt] = 0;
        do {
            scc[stk[stkTop]] = sccCnt;
            vis[stk[stkTop]] = 2;
            sccSize[sccCnt]++;
        } while (stk[stkTop--] != u);
    }
}

int tarjan(int n) {
    sccCnt = 0;
    stkTop = 0;
    int dep = 1;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, dep);
    return sccCnt;
}